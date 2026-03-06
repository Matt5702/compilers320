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

// Default visit implementations
void cSemantics::Visit(cAstNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cBlockNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cDeclsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cIntExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cFloatExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cBinaryExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cVarDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cStructDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cArrayDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cVarRefNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cAssignNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cIfNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cWhileNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cReturnNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cPrintsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cArgsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cParamsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cFuncDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cFuncCallNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cOpNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cPrintNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cProgramNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cStmtNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cStmtsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cSemantics::Visit(cSymbol *node)
{
    // Symbols don't have children
}

bool cSemantics::IsTypeCompatible(cDeclNode *type1, cDeclNode *type2)
{
    // TODO: Implement type compatibility checking
    if (type1 == nullptr || type2 == nullptr)
        return false;
    
    return type1 == type2;
}
