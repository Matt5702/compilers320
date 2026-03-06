//**************************************
// cSemantics.cpp
//
// Implementation of semantic analysis and error checking
//
// Author: Phil Howard
// phil.howard@oit.edu
//

#include "cSemantics.h"
#include "astnodes.h"

void cSemantics::VisitAllNodes(cAstNode *node)
{
    if (node != nullptr)
    {
        node->Visit(this);
    }
}

void cSemantics::Visit(cAstNode *node)            { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cBlockNode *node)          { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cDeclNode *node)           { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cDeclsNode *node)          { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cExprNode *node)           { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cIntExprNode *node)        { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cFloatExprNode *node)      { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cBinaryExprNode *node)     { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cVarDeclNode *node)        { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cStructDeclNode *node)     { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cArrayDeclNode *node)      { if (node) node->VisitAllChildren(this); }

void cSemantics::Visit(cVarRefNode *node)
{
    if (node == nullptr) return;

    cDeclNode *decl = node->GetDecl();
    if (decl != nullptr && decl->IsFunc())
    {
        cSymbol *sym = node->GetSymbol();
        if (sym != nullptr)
        {
            node->SemanticError("Symbol " + sym->GetName() + " is a function, not a variable");
        }
    }

    cDeclNode *curType = nullptr;
    cVarDeclNode *varDecl = dynamic_cast<cVarDeclNode*>(decl);
    if (varDecl != nullptr)
    {
        curType = varDecl->GetDeclaredTypeDecl();
    }
    else if (decl != nullptr)
    {
        curType = decl->GetType();
    }

    for (int i = 0; i < node->NumParts(); i++)
    {
        cAstNode *part = node->GetPart(i);
        cExprNode *indexExpr = dynamic_cast<cExprNode*>(part);
        if (indexExpr != nullptr)
        {
            cSymbol *sym = node->GetSymbol();
            string symName = (sym != nullptr) ? sym->GetName() : string("symbol");

            if (curType == nullptr || !curType->IsArray())
            {
                node->SemanticError(symName + " is not an array");
                break;
            }

            cDeclNode *indexType = indexExpr->GetType();
            if (indexType == nullptr || !indexType->IsInt())
            {
                node->SemanticError("Index of " + symName + " is not an int");
            }

            curType = curType->GetType();
        }
        else
        {
            cSymbol *fieldSym = dynamic_cast<cSymbol*>(part);
            if (fieldSym != nullptr && fieldSym->GetDecl() != nullptr)
            {
                curType = fieldSym->GetDecl()->GetType();
            }
        }
    }

    node->VisitAllChildren(this);
}

void cSemantics::Visit(cAssignNode *node)
{
    if (node == nullptr) return;

    node->VisitAllChildren(this);

    cVarRefNode *leftExpr = node->GetLVal();
    cExprNode *rightExpr = node->GetExpr();

    if (leftExpr == nullptr || rightExpr == nullptr)
        return;

    cDeclNode *leftType = leftExpr->GetType();
    cDeclNode *rightType = rightExpr->GetType();

    if (leftType != nullptr && rightType != nullptr && !leftType->IsCompatibleWith(rightType))
    {
        node->SemanticError("Cannot assign " + GetTypeName(rightType) + " to " + GetTypeName(leftType));
    }
}

void cSemantics::Visit(cIfNode *node)             { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cWhileNode *node)          { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cReturnNode *node)         { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cPrintsNode *node)         { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cArgsNode *node)           { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cParamsNode *node)         { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cFuncDeclNode *node)       { if (node) node->VisitAllChildren(this); }

void cSemantics::Visit(cFuncCallNode *node)
{
    if (node == nullptr) return;

    node->VisitAllChildren(this);

    cSymbol *funcSym = node->GetSymbol();
    if (funcSym == nullptr || funcSym->GetDecl() == nullptr)
        return;

    cFuncDeclNode *funcDecl = dynamic_cast<cFuncDeclNode*>(funcSym->GetDecl());
    if (funcDecl == nullptr)
        return;

    if (!funcDecl->IsFullyDefined())
    {
        node->SemanticError("Function " + funcSym->GetName() + " is not fully defined");
        return;
    }

    cArgsNode *args = funcDecl->GetArgs();
    cParamsNode *params = node->GetParams();

    int expected = (args != nullptr) ? args->NumArgs() : 0;
    int actual = (params != nullptr) ? params->NumParams() : 0;

    if (expected != actual)
    {
        node->SemanticError(funcSym->GetName() + " called with wrong number of arguments");
        return;
    }

    for (int i = 0; i < expected; i++)
    {
        cDeclNode *formalDecl = args->GetArg(i);
        cExprNode *actualExpr = params->GetParam(i);

        if (formalDecl == nullptr || actualExpr == nullptr)
            continue;

        cDeclNode *formalType = formalDecl->GetType();
        cDeclNode *actualType = actualExpr->GetType();

        if (formalType == nullptr || actualType == nullptr)
            continue;

        if (!formalType->IsCompatibleWith(actualType))
        {
            node->SemanticError(funcSym->GetName() + " called with incompatible argument");
            return;
        }
    }
}

void cSemantics::Visit(cOpNode *node)             { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cPrintNode *node)          { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cProgramNode *node)        { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cStmtNode *node)           { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cStmtsNode *node)          { if (node) node->VisitAllChildren(this); }
void cSemantics::Visit(cSymbol *node)             { (void)node; }

bool cSemantics::IsTypeCompatible(cDeclNode *type1, cDeclNode *type2)
{
    if (type1 == nullptr || type2 == nullptr)
        return false;

    return type1->IsCompatibleWith(type2);
}

string cSemantics::GetTypeName(cDeclNode *type)
{
    if (type == nullptr)
        return "unknown";

    return type->GetName();
}
