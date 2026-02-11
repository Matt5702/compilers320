#pragma once
//**************************************
// cFuncDeclNode.h
//
// Defines AST node for function declarations and definitions
//
// Author: Phil Howard
//

#include "cDeclNode.h"
#include "cArgsNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cSymbol.h"

class cFuncDeclNode : public cDeclNode
{
    public:
        cFuncDeclNode(cSymbol *type, cSymbol *name, cArgsNode *args)
            : cDeclNode()
        {
            AddChild(type);
            AddChild(name);
            if (args != nullptr)
                AddChild(args);
        }

        void AppendArgs(cArgsNode *args)
        {
            if (args != nullptr)
                AddChild(args);
        }

        void AppendDecls(cDeclsNode *decls)
        {
            if (decls != nullptr)
                AddChild(decls);
        }

        void AppendStmts(cStmtsNode *stmts)
        {
            if (stmts != nullptr)
                AddChild(stmts);
        }

        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
};
