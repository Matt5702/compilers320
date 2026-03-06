#pragma once
//**************************************
// cAssignNode.h
//
// Defines AST node for assignments
//
// Author: Phil Howard
//

#include "cStmtNode.h"
#include "cVarRefNode.h"
#include "cExprNode.h"

class cAssignNode : public cStmtNode
{
    public:
        cAssignNode(cVarRefNode *lval, cExprNode *expr) : cStmtNode()
        {
            AddChild(lval);
            AddChild(expr);
            m_lval = lval;
            m_expr = expr;
        }

        virtual string NodeType() { return string("assign"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        cVarRefNode *GetLVal() { return m_lval; }
        cExprNode *GetExpr() { return m_expr; }

    private:
        cVarRefNode *m_lval;
        cExprNode *m_expr;
};
