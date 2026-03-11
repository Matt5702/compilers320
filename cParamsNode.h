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
            m_size = 0;
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

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }

        virtual string AttributesToString()
        {
            if (m_size == 0) return string("");
            return " size=\"" + std::to_string(m_size) + "\"";
        }

    private:
        int m_size;
};
