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

void cCodeGen::VisitAllNodes(cAstNode *node)
{
    if (node != nullptr)
    {
        node->Visit(this);
    }
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
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cDeclsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
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
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cFloatExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cBinaryExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cVarDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cStructDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cArrayDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cVarRefNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cAssignNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cIfNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cWhileNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cReturnNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cPrintsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cArgsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cParamsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cFuncDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cFuncCallNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cOpNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cPrintNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cProgramNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
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
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cCodeGen::Visit(cSymbol *node)
{
    // Symbols don't have children
}
