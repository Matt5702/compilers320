#pragma once
//**************************************
// cDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode(), m_size(0), m_offset(0) {}
        
        // Virtual methods for type introspection
        virtual bool IsArray()  { return false; }
        virtual bool IsStruct() { return false; }
        virtual bool IsType()   { return false; }
        virtual bool IsFunc()   { return false; }
        virtual bool IsVar()    { return false; }
        virtual bool IsFloat()  { return false; }
        virtual bool IsInt()    { return false; }
        virtual bool IsChar()   { return false; }
        virtual int  GetSize()  { return m_size; }
        virtual int  GetOffset() { return m_offset; }
        virtual void SetSize(int size) { m_size = size; }
        virtual void SetOffset(int offset) { m_offset = offset; }
        virtual cDeclNode *GetType() = 0;
        virtual string GetName() = 0;

        virtual string AttributesToString()
        {
            if (m_size == 0 && m_offset == 0) return string("");
            return " size=\"" + std::to_string(m_size) +
                   "\" offset=\"" + std::to_string(m_offset) + "\"";
        }
        
        // Get the decl for this declaration (returns this by default)
        virtual cDeclNode *GetDecl() { return this; }
        
        // Check if this type is compatible with another type
        virtual bool IsCompatibleWith(cDeclNode *type);

    protected:
        int m_size;
        int m_offset;
};
