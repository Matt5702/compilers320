#pragma once
//**************************************
// cComputeSize.h
//
// Visitor class for computing sizes of data structures
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cVisitor.h"

class cComputeSize : public cVisitor
{
    public:
        cComputeSize() {}

        // The VisitAllNodes method starts traversal at the root
        virtual void VisitAllNodes(cAstNode *node);
        
        // Visit methods for each node type
        virtual void Visit(cAstNode *node);
        virtual void Visit(cBlockNode *node);
        virtual void Visit(cDeclNode *node);
        virtual void Visit(cDeclsNode *node);
        virtual void Visit(cExprNode *node);
        virtual void Visit(cIntExprNode *node);
        virtual void Visit(cFloatExprNode *node);
        virtual void Visit(cBinaryExprNode *node);
        virtual void Visit(cVarDeclNode *node);
        virtual void Visit(cStructDeclNode *node);
        virtual void Visit(cArrayDeclNode *node);
        virtual void Visit(cVarRefNode *node);
        virtual void Visit(cAssignNode *node);
        virtual void Visit(cIfNode *node);
        virtual void Visit(cWhileNode *node);
        virtual void Visit(cReturnNode *node);
        virtual void Visit(cPrintsNode *node);
        virtual void Visit(cArgsNode *node);
        virtual void Visit(cParamsNode *node);
        virtual void Visit(cFuncDeclNode *node);
        virtual void Visit(cFuncCallNode *node);
        virtual void Visit(cOpNode *node);
        virtual void Visit(cPrintNode *node);
        virtual void Visit(cProgramNode *node);
        virtual void Visit(cStmtNode *node);
        virtual void Visit(cStmtsNode *node);
        virtual void Visit(cSymbol *node);
};
