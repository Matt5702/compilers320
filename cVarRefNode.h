#pragma once
//**************************************
// cVarRefNode.h
//
// Defines AST node for variable references
//
// Author: Phil Howard
//

#include "cExprNode.h"
#include "cSymbol.h"
#include "cVarDeclNode.h"

class cVarRefNode : public cExprNode
{
    public:
        cVarRefNode(cSymbol *name) : cExprNode()
        {
            AddChild(name);
            m_symbol = name;
        }

        void AddPart(cAstNode *part)
        {
            AddChild(part);
        }

        virtual string NodeType() { return string("varref"); }
        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
        
        // Return the declaration of the symbol being referenced
        virtual cDeclNode *GetDecl()
        {
            if (m_symbol != nullptr)
                return m_symbol->GetDecl();
            
            return nullptr;
        }
        
        // Return the type of this expression
        virtual cDeclNode *GetType()
        {
            cDeclNode *decl = GetDecl();
            if (decl == nullptr)
                return nullptr;

            cDeclNode *curType = nullptr;
            cVarDeclNode *varDecl = dynamic_cast<cVarDeclNode*>(decl);
            if (varDecl != nullptr)
            {
                curType = varDecl->GetDeclaredTypeDecl();
            }
            else
            {
                curType = decl->GetType();
            }

            for (int i = 0; i < NumParts(); i++)
            {
                cAstNode *part = GetPart(i);
                if (dynamic_cast<cExprNode*>(part) != nullptr)
                {
                    if (curType != nullptr && curType->IsArray())
                    {
                        curType = curType->GetType();
                    }
                    else
                    {
                        return nullptr;
                    }
                }
                else
                {
                    cSymbol *fieldSym = dynamic_cast<cSymbol*>(part);
                    if (fieldSym != nullptr && fieldSym->GetDecl() != nullptr)
                    {
                        curType = fieldSym->GetDecl()->GetType();
                    }
                }
            }

            return curType;
        }

        cSymbol *GetSymbol() { return m_symbol; }
        int NumParts() { return NumChildren() - 1; }
        cAstNode *GetPart(int index) { return GetChild(index + 1); }
        
    private:
        cSymbol *m_symbol;  // The symbol being referenced
};
