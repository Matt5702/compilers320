#pragma once
//**************************************
// cPrintsNode.h
//
// Defines AST node for prints statements
//
// Author: Phil Howard
//

#include "cStmtNode.h"

class cPrintsNode : public cStmtNode
{
    public:
        cPrintsNode(const std::string &value) : cStmtNode(), m_value(value) {}

        virtual string NodeType() { return string("prints"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        virtual string AttributesToString()
        {
            return " value=\"" + m_value + "\"";
        }

    protected:
        std::string m_value;
};
