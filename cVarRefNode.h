#pragma once
//**************************************
// cVarRefNode.h
//
// Defines AST node for variable references
//
// Author: Phil Howard
//

#include "cExprNode.h"
#include "cSymbol.h"

class cVarRefNode : public cExprNode
{
    public:
        cVarRefNode(cSymbol *name) : cExprNode()
        {
            AddChild(name);
        }

        void AddPart(cAstNode *part)
        {
            AddChild(part);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
