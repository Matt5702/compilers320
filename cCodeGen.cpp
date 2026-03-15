//**************************************
// cCodeGen.cpp
//
// Implementation of code generation
//
// Author: Phil Howard
// phil.howard@oit.edu
//

#include "cCodeGen.h"
#include "astnodes.h"
#include "emit.h"

#include <sstream>

namespace
{
    constexpr int WORD_SIZE = 4;

    int RoundUpToWord(int value)
    {
        if (value <= WORD_SIZE) return WORD_SIZE;
        int rem = value % WORD_SIZE;
        if (rem == 0) return value;
        return value + (WORD_SIZE - rem);
    }
}

void cCodeGen::EmitLine(const string &text)
{
    EmitString(text);
    EmitString("\n");
}

void cCodeGen::EmitPushInt(int value)
{
    EmitLine("PUSH " + std::to_string(value));
}

void cCodeGen::EmitPushAddress(int offset)
{
    EmitPushInt(offset);
    EmitLine("PUSHFP");
    EmitLine("PLUS");
}

void cCodeGen::EmitLoadFromAddress(cDeclNode *type)
{
    if (type != nullptr && type->GetSize() == 1)
    {
        EmitLine("PUSHCVARIND");
    }
    else
    {
        EmitLine("PUSHVARIND");
    }
}

void cCodeGen::EmitStoreToAddress(cDeclNode *type)
{
    if (type != nullptr && type->GetSize() == 1)
    {
        EmitLine("POPCVARIND");
    }
    else
    {
        EmitLine("POPVARIND");
    }
}

void cCodeGen::EmitValueToBool()
{
    string falseLabel = GenerateLabel();
    string endLabel = GenerateLabel();

    EmitLine("JUMPE @" + falseLabel);
    EmitPushInt(1);
    EmitLine("JUMP @" + endLabel);
    EmitLine(falseLabel + ":");
    EmitPushInt(0);
    EmitLine(endLabel + ":");
}

void cCodeGen::EmitCleanupAfterCall(int numParams, bool keepReturnValue)
{
    for (int i = 0; i < numParams; i++)
    {
        EmitLine("SWAP");
        EmitLine("POP");
    }

    if (!keepReturnValue)
    {
        EmitLine("POP");
    }
}

void cCodeGen::EmitVarAddress(cVarRefNode *node)
{
    if (node == nullptr) return;

    EmitPushAddress(node->GetOffset());

    int rowIndex = 0;
    for (int i = 0; i < node->NumParts() && rowIndex < node->NumRowSizes(); i++)
    {
        cExprNode *indexExpr = dynamic_cast<cExprNode*>(node->GetPart(i));
        if (indexExpr == nullptr) continue;

        indexExpr->Visit(this);
        EmitPushInt(node->GetRowSize(rowIndex));
        EmitLine("TIMES");
        EmitLine("PLUS");
        rowIndex++;
    }
}

string cCodeGen::EscapeString(const string &value) const
{
    std::ostringstream out;

    for (char ch : value)
    {
        switch (ch)
        {
            case '\\': out << "\\\\"; break;
            case '"': out << "\\\""; break;
            case '\n': out << "\\n"; break;
            case '\t': out << "\\t"; break;
            default: out << ch; break;
        }
    }

    return out.str();
}

void cCodeGen::EmitStringLiteral(const string &value)
{
    string label = GenerateLabel();
    EmitLine("PUSH @" + label);
    EmitLine(".dataseg");
    EmitLine(label + ":");
    EmitLine(".string \"" + EscapeString(value) + "\"");
    EmitLine(".codeseg");
    EmitLine("OUTS");
}

void cCodeGen::VisitAllNodes(cAstNode *node)
{
    if (node == nullptr) return;
    if (!InitOutput(m_filename)) return;

    node->Visit(this);

    FinalizeOutput();
}

// Default visit implementations
void cCodeGen::Visit(cAstNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cBlockNode *node)
{
    if (node == nullptr) return;

    if (node->GetStmts() != nullptr)
    {
        node->GetStmts()->Visit(this);
    }
}

void cCodeGen::Visit(cDeclNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cDeclsNode *node)
{
    if (node == nullptr) return;

    for (int i = 0; i < node->NumDecls(); i++)
    {
        cDeclNode *decl = node->GetDecl(i);
        cFuncDeclNode *func = dynamic_cast<cFuncDeclNode*>(decl);
        if (func != nullptr && func->IsFullyDefined())
        {
            func->Visit(this);
        }
    }
}

void cCodeGen::Visit(cExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cIntExprNode *node)
{
    if (node == nullptr) return;
    EmitPushInt(node->GetValue());
}

void cCodeGen::Visit(cFloatExprNode *node)
{
    if (node == nullptr) return;
    EmitPushInt(static_cast<int>(node->GetValue()));
}

void cCodeGen::Visit(cBinaryExprNode *node)
{
    if (node == nullptr) return;

    cExprNode *left = node->GetLeft();
    cExprNode *right = node->GetRight();
    cOpNode *opNode = node->GetOp();
    if (left == nullptr || right == nullptr || opNode == nullptr) return;

    int op = opNode->GetOp();

    if (op == AND)
    {
        string falseLabel = GenerateLabel();
        string endLabel = GenerateLabel();

        left->Visit(this);
        EmitLine("JUMPE @" + falseLabel);
        right->Visit(this);
        EmitLine("JUMPE @" + falseLabel);
        EmitPushInt(1);
        EmitLine("JUMP @" + endLabel);
        EmitLine(falseLabel + ":");
        EmitPushInt(0);
        EmitLine(endLabel + ":");
        return;
    }

    if (op == OR)
    {
        string rhsLabel = GenerateLabel();
        string falseLabel = GenerateLabel();
        string endLabel = GenerateLabel();

        left->Visit(this);
        EmitLine("JUMPE @" + rhsLabel);
        EmitPushInt(1);
        EmitLine("JUMP @" + endLabel);
        EmitLine(rhsLabel + ":");
        right->Visit(this);
        EmitLine("JUMPE @" + falseLabel);
        EmitPushInt(1);
        EmitLine("JUMP @" + endLabel);
        EmitLine(falseLabel + ":");
        EmitPushInt(0);
        EmitLine(endLabel + ":");
        return;
    }

    left->Visit(this);
    right->Visit(this);

    switch (op)
    {
        case '+':
            EmitLine("PLUS");
            break;
        case '-':
            EmitLine("MINUS");
            break;
        case '*':
            EmitLine("TIMES");
            break;
        case '/':
            EmitLine("DIVIDE");
            break;
        case '%':
            EmitLine("MOD");
            break;
        case EQUALS:
            EmitLine("EQ");
            break;
        case NOT_EQUALS:
            EmitLine("EQ");
            EmitPushInt(0);
            EmitLine("EQ");
            break;
        case '>':
            EmitLine("GT");
            break;
        case '<':
            EmitLine("LT");
            break;
        case GE:
            EmitLine("LT");
            EmitPushInt(0);
            EmitLine("EQ");
            break;
        case LE:
            EmitLine("GT");
            EmitPushInt(0);
            EmitLine("EQ");
            break;
        default:
            break;
    }
}

void cCodeGen::Visit(cVarDeclNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cStructDeclNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cArrayDeclNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cVarRefNode *node)
{
    if (node == nullptr) return;

    EmitVarAddress(node);
    EmitLoadFromAddress(node->GetType());
}

void cCodeGen::Visit(cAssignNode *node)
{
    if (node == nullptr) return;

    cExprNode *expr = node->GetExpr();
    cVarRefNode *lval = node->GetLVal();
    if (expr == nullptr || lval == nullptr) return;

    expr->Visit(this);
    EmitLine("DUP");
    EmitVarAddress(lval);
    EmitStoreToAddress(lval->GetType());
    EmitLine("POP");
}

void cCodeGen::Visit(cIfNode *node)
{
    if (node == nullptr) return;

    cExprNode *cond = node->GetCond();
    cStmtsNode *thenStmts = node->GetThenStmts();
    cStmtsNode *elseStmts = node->GetElseStmts();
    if (cond == nullptr || thenStmts == nullptr) return;

    string elseLabel = GenerateLabel();
    string endLabel = GenerateLabel();

    cond->Visit(this);
    EmitLine("JUMPE @" + elseLabel);
    thenStmts->Visit(this);
    EmitLine("JUMP @" + endLabel);
    EmitLine(elseLabel + ":");
    if (elseStmts != nullptr)
    {
        elseStmts->Visit(this);
    }
    EmitLine(endLabel + ":");
}

void cCodeGen::Visit(cWhileNode *node)
{
    if (node == nullptr) return;

    cExprNode *cond = node->GetCond();
    cStmtNode *body = node->GetBody();
    if (cond == nullptr || body == nullptr) return;

    string topLabel = GenerateLabel();
    string endLabel = GenerateLabel();

    EmitLine(topLabel + ":");
    cond->Visit(this);
    EmitLine("JUMPE @" + endLabel);
    body->Visit(this);
    EmitLine("JUMP @" + topLabel);
    EmitLine(endLabel + ":");
}

void cCodeGen::Visit(cReturnNode *node)
{
    if (node == nullptr) return;

    cExprNode *expr = node->GetExpr();
    if (expr != nullptr)
    {
        expr->Visit(this);
    }
    else
    {
        EmitPushInt(0);
    }

    EmitLine("RETURNV");
}

void cCodeGen::Visit(cPrintsNode *node)
{
    if (node == nullptr) return;

    EmitStringLiteral(node->GetString());
    EmitStringLiteral("\n");
}

void cCodeGen::Visit(cArgsNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cParamsNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cFuncDeclNode *node)
{
    if (node == nullptr || !node->IsFullyDefined()) return;

    cFuncDeclNode *savedFunction = m_currentFunction;
    m_currentFunction = node;

    EmitLine(".function " + node->GetName());
    EmitLine(node->GetName() + ":");
    if (node->GetSize() > 0)
    {
        EmitLine("ADJSP " + std::to_string(RoundUpToWord(node->GetSize())));
    }

    if (node->GetStmts() != nullptr)
    {
        node->GetStmts()->Visit(this);
    }

    EmitPushInt(0);
    EmitLine("RETURNV");

    m_currentFunction = savedFunction;
}

void cCodeGen::Visit(cFuncCallNode *node)
{
    if (node == nullptr || node->GetSymbol() == nullptr) return;

    cParamsNode *params = node->GetParams();
    int numParams = (params != nullptr) ? params->NumParams() : 0;

    for (int i = numParams - 1; i >= 0; i--)
    {
        cExprNode *param = params->GetParam(i);
        if (param != nullptr)
        {
            param->Visit(this);
        }
    }

    EmitLine("CALL @" + node->GetSymbol()->GetName());
    EmitCleanupAfterCall(numParams, true);
}

void cCodeGen::Visit(cOpNode *node)
{
    (void)node;
}

void cCodeGen::Visit(cPrintNode *node)
{
    if (node == nullptr || node->GetExpr() == nullptr) return;

    node->GetExpr()->Visit(this);
    EmitLine("CALL @print");
    EmitCleanupAfterCall(1, false);
}

void cCodeGen::Visit(cProgramNode *node)
{
    if (node == nullptr) return;

    cBlockNode *block = node->GetBlock();
    if (block == nullptr)
    {
        EmitLine(".function main");
        EmitLine("main:");
        EmitPushInt(0);
        EmitLine("RETURNV");
        return;
    }

    if (block->GetDecls() != nullptr)
    {
        block->GetDecls()->Visit(this);
    }

    EmitLine(".function main");
    EmitLine("main:");
    if (block->GetSize() > 0)
    {
        EmitLine("ADJSP " + std::to_string(RoundUpToWord(block->GetSize())));
    }
    if (block->GetStmts() != nullptr)
    {
        block->GetStmts()->Visit(this);
    }
    EmitPushInt(0);
    EmitLine("RETURNV");
}

void cCodeGen::Visit(cStmtNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cStmtsNode *node)
{
    if (node == nullptr) return;

    for (int i = 0; i < node->NumStmts(); i++)
    {
        cStmtNode *stmt = node->GetStmt(i);
        if (stmt == nullptr) continue;

        stmt->Visit(this);

        if (dynamic_cast<cFuncCallNode*>(stmt) != nullptr)
        {
            EmitLine("POP");
        }
    }
}

void cCodeGen::Visit(cSymbol *node)
{
    (void)node;
}
