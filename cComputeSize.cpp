//**************************************
// cComputeSize.cpp
//
// Implementation of size computation for data structures
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cComputeSize.h"
#include "astnodes.h"

void cComputeSize::VisitAllNodes(cAstNode *node)
{
    if (node != nullptr)
    {
        node->Visit(this);
    }
}

// Default visit implementations
void cComputeSize::Visit(cAstNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cBlockNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cDeclsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cIntExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cFloatExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cBinaryExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cVarDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cStructDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cArrayDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cVarRefNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cAssignNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cIfNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cWhileNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cReturnNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cPrintsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cArgsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cParamsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cFuncDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cFuncCallNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cOpNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cPrintNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cProgramNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cStmtNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cStmtsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cSymbol *node)
{
    // Symbols don't have children
}
