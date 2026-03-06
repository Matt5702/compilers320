#pragma once
//**************************************
// cParamsNode.h
//
// Defines AST node for function call parameters
//
// Author: Phil Howard
//

#include "cAstNode.h"
#include "cExprNode.h"

class cParamsNode : public cAstNode
{
    public:
        cParamsNode(cExprNode *expr) : cAstNode()
        {
            AddChild(expr);
        }

        void Insert(cExprNode *expr)
        {
            AddChild(expr);
        }

        virtual string NodeType() { return string("params"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        int NumParams() { return NumChildren(); }
        cExprNode *GetParam(int index)
        {
            return dynamic_cast<cExprNode*>(GetChild(index));
        }
};
