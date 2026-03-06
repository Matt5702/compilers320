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
            m_symbol = name;
        }

        void AddPart(cAstNode *part)
        {
            AddChild(part);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Return the declaration of the symbol being referenced
        virtual cDeclNode *GetDecl()
        {
            if (m_symbol != nullptr)
                return m_symbol->GetDecl();
            
            return nullptr;
        }
        
        // Return the type of this expression
        virtual cDeclNode *GetType()
        {
            if (m_symbol != nullptr && m_symbol->GetDecl() != nullptr)
                return m_symbol->GetDecl()->GetType();
            
            return nullptr;
        }
        
    private:
        cSymbol *m_symbol;  // The symbol being referenced
};
