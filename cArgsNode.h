#pragma once
//**************************************
// cArgsNode.h
//
// Defines AST node for function argument lists
//
// Author: Phil Howard
//

#include "cAstNode.h"
#include "cVarDeclNode.h"

class cArgsNode : public cAstNode
{
    public:
        cArgsNode(cDeclNode *decl) : cAstNode()
        {
            AddChild(decl);
        }

        void Insert(cDeclNode *decl)
        {
            AddChild(decl);
        }

        virtual string NodeType() { return string("args"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        int NumArgs() { return NumChildren(); }
        cDeclNode *GetArg(int index)
        {
            return dynamic_cast<cDeclNode*>(GetChild(index));
        }
};
