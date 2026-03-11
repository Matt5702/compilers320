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
            m_type = type;
            m_name = name;
            m_args = args;
            m_decls = nullptr;
            m_stmts = nullptr;
            m_isDefined = false;
            if (args != nullptr)
                AddChild(args);
        }

        void AppendArgs(cArgsNode *args)
        {
            if (args != nullptr)
            {
                AddChild(args);
                m_args = args;
            }
        }

        void AppendDecls(cDeclsNode *decls)
        {
            if (decls != nullptr)
            {
                AddChild(decls);
                m_decls = decls;
            }
        }

        void AppendStmts(cStmtsNode *stmts)
        {
            if (stmts != nullptr)
            {
                AddChild(stmts);
                m_stmts = stmts;
                m_isDefined = true;
            }
        }

        virtual string NodeType() { return string("func"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Functions are funcs
        virtual bool IsFunc() { return true; }
        virtual string GetName() { return m_name != nullptr ? m_name->GetName() : ""; }
        
        // Return the return type of this function
        virtual cDeclNode *GetType()
        {
            if (m_type != nullptr && m_type->GetDecl() != nullptr)
                return m_type->GetDecl()->GetType();
            
            return nullptr;
        }

        cArgsNode *GetArgs() { return m_args; }
        cDeclsNode *GetDecls() { return m_decls; }
        cStmtsNode *GetStmts() { return m_stmts; }
        bool IsFullyDefined() { return m_isDefined; }
        cSymbol *GetSymbol() { return m_name; }
        cSymbol *GetTypeSymbol() { return m_type; }
        
    private:
        cSymbol *m_type;    // The return type of this function
        cSymbol *m_name;    // The function name
        cArgsNode *m_args;  // Formal arguments
        cDeclsNode *m_decls;
        cStmtsNode *m_stmts;
        bool m_isDefined;   // True if function has body
};

