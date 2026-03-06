#pragma once
//**************************************
// cStructDeclNode.h
//
// Defines AST node for struct declarations
//
// Author: Phil Howard
//

#include "cDeclNode.h"
#include "cDeclsNode.h"
#include "cSymbol.h"

class cStructDeclNode : public cDeclNode
{
    public:
        cStructDeclNode(cDeclsNode *decls, cSymbol *name) : cDeclNode()
        {
            AddChild(decls);
            AddChild(name);
            m_name = name;
        }

        virtual string NodeType() { return string("struct_decl"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Structs are types
        virtual bool IsType() { return true; }
        virtual bool IsStruct() { return true; }
        
        // Struct types return themselves as the type
        virtual cDeclNode *GetType() { return this; }
        
    private:
        cSymbol *m_name;    // The name of the struct
};
