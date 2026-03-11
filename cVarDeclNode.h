#pragma once
//**************************************
// cVarDeclNode.h
//
// Defines AST node for variable declarations
//
// Author: Phil Howard
//

#include "cDeclNode.h"
#include "cSymbol.h"

class cVarDeclNode : public cDeclNode
{
    public:
        cVarDeclNode(cSymbol *type, cSymbol *name) : cDeclNode()
        {
            AddChild(type);
            AddChild(name);
            m_type = type;
            m_name = name;
        }

        virtual string NodeType() { return string("var_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Variables are vars
        virtual bool IsVar() { return true; }
        virtual string GetName() { return m_name != nullptr ? m_name->GetName() : ""; }
        
        // Return the type this variable declares
        virtual cDeclNode *GetType()
        {
            if (m_type != nullptr && m_type->GetDecl() != nullptr)
                return m_type->GetDecl()->GetType();
            
            return nullptr;
        }

        cDeclNode *GetDeclaredTypeDecl()
        {
            if (m_type != nullptr)
                return m_type->GetDecl();

            return nullptr;
        }

        cSymbol *GetSymbol() { return m_name; }
        
    private:
        cSymbol *m_type;    // The type of this variable
        cSymbol *m_name;    // The variable name symbol
};
