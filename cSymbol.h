#pragma once
//********************************************************
// cSymbol.h - Define a class for symbols
//
// Author: Philip Howard
//
#include <string>

using std::string;

#include "cAstNode.h"

// Forward declaration to avoid circular dependency
class cDeclNode;

class cSymbol : public cAstNode
{
    public:
        // Construct a symbol given its name
        cSymbol(string name) : cAstNode()
        {
            m_id = ++nextId;
            m_name = name;
            m_decl = nullptr;
        }

        // Return a string representation of a symbol
        // Return value is an XML node
        virtual string AttributesToString()
        {
            string result(" id=\"");
            result += std::to_string(m_id);
            result += "\" name=\"" + m_name + "\"";
            return result;
        }

        virtual string NodeType() { return string("sym"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

        string GetName() const { return m_name; }
        
        // Replace IsType() with GetDecl() pattern
        cDeclNode *GetDecl() const { return m_decl; }
        void SetDecl(cDeclNode *decl) { m_decl = decl; }
        
    protected:
        static long long nextId;    // keeps track of unique symbol IDs
        long long m_id;             // Unique ID for this symbol
        string m_name;              // Symbol name
        cDeclNode *m_decl;          // Pointer to declaration node
};
