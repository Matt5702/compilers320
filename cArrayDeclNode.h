#pragma once
//**************************************
// cArrayDeclNode.h
//
// Defines AST node for array declarations
//
// Author: Phil Howard
//

#include "cDeclNode.h"
#include "cSymbol.h"

class cArrayDeclNode : public cDeclNode
{
    public:
        cArrayDeclNode(cSymbol *type, cSymbol *name, int count)
            : cDeclNode(), m_count(count)
        {
            AddChild(type);
            AddChild(name);
            m_type = type;
        }

        virtual string NodeType() { return string("array_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual string AttributesToString()
        {
            return " count=\"" + std::to_string(m_count) + "\"";
        }
        
        // Arrays are also types (can be used as type names)
        virtual bool IsType() { return true; }
        virtual bool IsArray() { return true; }
        
        // Return the element type of this array
        virtual cDeclNode *GetType()
        {
            if (m_type != nullptr && m_type->GetDecl() != nullptr)
                return m_type->GetDecl()->GetType();
            
            return nullptr;
        }

    protected:
        int m_count;
        cSymbol *m_type;    // The element type of this array
};
