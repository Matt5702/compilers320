#pragma once
//**************************************
// cFuncCallNode.h
//
// Defines AST node for function calls
//
// Author: Phil Howard
//

#include "cExprNode.h"
#include "cParamsNode.h"
#include "cSymbol.h"

class cFuncCallNode : public cExprNode
{
    public:
        cFuncCallNode(cSymbol *name, cParamsNode *params) : cExprNode()
        {
            AddChild(name);
            if (params != nullptr)
                AddChild(params);
        }

        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
