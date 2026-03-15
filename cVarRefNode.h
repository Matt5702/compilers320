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
#include "cStructDeclNode.h"
#include <vector>

class cVarRefNode : public cExprNode
{
    public:
        cVarRefNode(cSymbol *name) : cExprNode()
        {
            AddChild(name);
            m_symbol = name;
            m_size = 0;
            m_offset = 0;
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
                    if (fieldSym != nullptr)
                    {
                        cDeclNode *fieldDecl = fieldSym->GetDecl();

                        if (fieldDecl == nullptr)
                        {
                            cStructDeclNode *structType = dynamic_cast<cStructDeclNode*>(curType);
                            if (structType != nullptr && structType->GetDecls() != nullptr)
                            {
                                cDeclsNode *fields = structType->GetDecls();
                                for (int j = 0; j < fields->NumDecls(); j++)
                                {
                                    cVarDeclNode *fieldVar = dynamic_cast<cVarDeclNode*>(fields->GetDecl(j));
                                    if (fieldVar != nullptr && fieldVar->GetSymbol() != nullptr &&
                                        fieldVar->GetSymbol()->GetName() == fieldSym->GetName())
                                    {
                                        fieldDecl = fieldVar;
                                        break;
                                    }
                                }
                            }
                        }

                        if (fieldDecl != nullptr)
                        {
                            curType = fieldDecl->GetType();
                        }
                    }
                }
            }

            return curType;
        }

        cSymbol *GetSymbol() { return m_symbol; }
        int NumParts() { return NumChildren() - 1; }
        cAstNode *GetPart(int index) { return GetChild(index + 1); }
        void SetPart(int index, cAstNode *part) { SetChild(index + 1, part); }

        int GetSize() { return m_size; }
        void SetSize(int size) { m_size = size; }
        int GetOffset() { return m_offset; }
        void SetOffset(int offset) { m_offset = offset; }

        void ClearRowSizes() { m_rowSizes.clear(); }
        void AddRowSize(int rowSize) { m_rowSizes.push_back(rowSize); }
        int NumRowSizes() { return (int)m_rowSizes.size(); }
        int GetRowSize(int index) { return m_rowSizes.at(index); }

        virtual string AttributesToString()
        {
            if (m_size == 0 && m_offset == 0 && m_rowSizes.empty())
                return string("");

            string result = " size=\"" + std::to_string(m_size) +
                            "\" offset=\"" + std::to_string(m_offset) + "\"";

            if (!m_rowSizes.empty())
            {
                result += " rowsizes=\"";
                for (size_t i = 0; i < m_rowSizes.size(); i++)
                {
                    if (i > 0) result += " ";
                    result += std::to_string(m_rowSizes[i]);
                }
                result += "\"";
            }

            return result;
        }
        
    private:
        cSymbol *m_symbol;  // The symbol being referenced
        int m_size;
        int m_offset;
        std::vector<int> m_rowSizes;
};
