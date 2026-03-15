#pragma once
//**************************************
// cIfNode.h
//
// Defines AST node for if statements
//
// Author: Phil Howard
//

#include "cStmtNode.h"
#include "cExprNode.h"
#include "cStmtsNode.h"

class cIfNode : public cStmtNode
{
    public:
        cIfNode(cExprNode *cond, cStmtsNode *thenStmts, cStmtsNode *elseStmts)
            : cStmtNode()
        {
            AddChild(cond);
            AddChild(thenStmts);
            if (elseStmts != nullptr)
            {
                AddChild(elseStmts);
            }
        }

        virtual string NodeType() { return string("if"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        cExprNode *GetCond()
        {
            return dynamic_cast<cExprNode*>(GetChild(0));
        }

        cStmtsNode *GetThenStmts()
        {
            return dynamic_cast<cStmtsNode*>(GetChild(1));
        }

        cStmtsNode *GetElseStmts()
        {
            return dynamic_cast<cStmtsNode*>(GetChild(2));
        }
};
