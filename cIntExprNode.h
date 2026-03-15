#pragma once
//**************************************
// cIntExprNode.h
//
// Defines an AST node for an integer constant (literals).
//
// Inherits from cExprNode so that integer constants can be used anywhere 
// expressions are used.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbolTable.h"

class cIntExprNode : public cExprNode
{
    public:
        // param is the value of the integer constant
        cIntExprNode(int value) : cExprNode()
        {
            m_value = value;
        }

        virtual string AttributesToString() 
        {
            return " value=\"" + std::to_string(m_value) + "\"";
        }
        virtual string NodeType() { return string("int"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        int GetValue() { return m_value; }
        
        // Return the type of this expression
        // Values 0..127 are char type, otherwise int
        virtual cDeclNode *GetType()
        {
            cSymbol *typeSym = nullptr;
            if (m_value >= 0 && m_value <= 127)
            {
                typeSym = g_SymbolTable.Find("char");
            }
            else
            {
                typeSym = g_SymbolTable.Find("int");
            }
            
            if (typeSym != nullptr && typeSym->GetDecl() != nullptr)
                return typeSym->GetDecl()->GetType();
            
            return nullptr;
        }
        
    protected:
        int m_value;        // value of integer constant (literal)
};
