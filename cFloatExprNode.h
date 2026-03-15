#pragma once
//**************************************
// cFloatExprNode.h
//
// Defines AST node for float constants
//
// Author: Phil Howard
//

#include <iomanip>
#include <sstream>

#include "cExprNode.h"
#include "cSymbolTable.h"

class cFloatExprNode : public cExprNode
{
    public:
        cFloatExprNode(double value) : cExprNode(), m_value(value) {}

        virtual string AttributesToString()
        {
            std::ostringstream out;
            out.setf(std::ios::fixed);
            out << " value=\"" << std::setprecision(6) << m_value << "\"";
            return out.str();
        }

        virtual string NodeType() { return string("float"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        double GetValue() { return m_value; }
        
        // Return the type of this expression (float)
        virtual cDeclNode *GetType()
        {
            cSymbol *typeSym = g_SymbolTable.Find("float");
            
            if (typeSym != nullptr && typeSym->GetDecl() != nullptr)
                return typeSym->GetDecl()->GetType();
            
            return nullptr;
        }

    protected:
        double m_value;
};
