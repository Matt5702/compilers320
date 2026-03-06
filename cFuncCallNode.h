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
            m_funcSymbol = name;
            if (params != nullptr)
                AddChild(params);
        }

        virtual string NodeType() { return string("funcCall"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Return the return type of the function
        virtual cDeclNode *GetType()
        {
            if (m_funcSymbol != nullptr && m_funcSymbol->GetDecl() != nullptr)
                return m_funcSymbol->GetDecl()->GetType();
            
            return nullptr;
        }
        
    private:
        cSymbol *m_funcSymbol;  // The function being called
};
