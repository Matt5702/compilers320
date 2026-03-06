#pragma once
//**************************************
// cBinaryExprNode.h
//
// Defines AST node for binary expressions
//
// Author: Phil Howard
//

#include "cExprNode.h"
#include "cOpNode.h"

class cBinaryExprNode : public cExprNode
{
    public:
        cBinaryExprNode(cExprNode *left, cOpNode *op, cExprNode *right)
            : cExprNode()
        {
            AddChild(left);
            AddChild(op);
            AddChild(right);
        }

        virtual string NodeType() { return string("expr"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Return the type of this expression (type of left operand for now)
        virtual cDeclNode *GetType()
        {
            // Return the type of the left operand
            cAstNode *left = GetChild(0);
            if (left != nullptr)
            {
                cExprNode *leftExpr = dynamic_cast<cExprNode*>(left);
                if (leftExpr != nullptr)
                    return leftExpr->GetType();
            }
            return nullptr;
        }
};
