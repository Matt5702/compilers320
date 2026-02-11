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

    protected:
        double m_value;
};
