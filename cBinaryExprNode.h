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
#include "cSymbolTable.h"

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
            cExprNode *leftExpr = dynamic_cast<cExprNode*>(GetChild(0));
            cOpNode *opExpr = dynamic_cast<cOpNode*>(GetChild(1));
            cExprNode *rightExpr = dynamic_cast<cExprNode*>(GetChild(2));

            if (leftExpr == nullptr || rightExpr == nullptr || opExpr == nullptr)
                return nullptr;

            cDeclNode *leftType = leftExpr->GetType();
            cDeclNode *rightType = rightExpr->GetType();
            if (leftType == nullptr || rightType == nullptr)
                return nullptr;

            int op = opExpr->GetOp();
            if (op == EQUALS || op == NOT_EQUALS || op == '>' || op == '<' ||
                op == GE || op == LE || op == AND || op == OR)
            {
                cSymbol *intSym = g_SymbolTable.Find("int");
                if (intSym != nullptr && intSym->GetDecl() != nullptr)
                    return intSym->GetDecl()->GetType();
                return nullptr;
            }

            if ((leftType->IsInt() || leftType->IsFloat()) &&
                (rightType->IsInt() || rightType->IsFloat()))
            {
                if (leftType->IsFloat() && rightType->IsFloat())
                    return leftType->GetSize() >= rightType->GetSize() ? leftType : rightType;

                if (leftType->IsFloat()) return leftType;
                if (rightType->IsFloat()) return rightType;

                return leftType->GetSize() >= rightType->GetSize() ? leftType : rightType;
            }

            return leftType;
        }
};
