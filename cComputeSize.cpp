//**************************************
// cComputeSize.cpp
//
// Implementation of size computation for data structures
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include "cComputeSize.h"
#include "astnodes.h"

static cDeclNode *FindStructField(cDeclNode *type, const std::string &fieldName)
{
    cStructDeclNode *structType = dynamic_cast<cStructDeclNode*>(type);
    if (structType == nullptr) return nullptr;

    cDeclsNode *fields = structType->GetDecls();
    if (fields == nullptr) return nullptr;

    for (int i = 0; i < fields->NumDecls(); i++)
    {
        cVarDeclNode *fieldDecl = dynamic_cast<cVarDeclNode*>(fields->GetDecl(i));
        if (fieldDecl == nullptr) continue;

        cSymbol *fieldSym = fieldDecl->GetSymbol();
        if (fieldSym != nullptr && fieldSym->GetName() == fieldName)
        {
            return fieldDecl;
        }
    }

    return nullptr;
}

int cComputeSize::AlignOffset(int offset, int size)
{
    if (size > 1)
    {
        int rem = offset % WORD_SIZE;
        if (rem != 0) offset += (WORD_SIZE - rem);
    }

    return offset;
}

int cComputeSize::AllocateLocal(int size)
{
    m_nextOffset = AlignOffset(m_nextOffset, size);
    int offset = m_nextOffset;
    m_nextOffset += size;

    if (!m_scopeHigh.empty() && m_nextOffset > m_scopeHigh.back())
    {
        m_scopeHigh.back() = m_nextOffset;
    }

    return offset;
}

int cComputeSize::EnterScope()
{
    m_scopeStart.push_back(m_nextOffset);
    m_scopeHigh.push_back(m_nextOffset);
    return m_nextOffset;
}

int cComputeSize::LeaveScope()
{
    int start = m_scopeStart.back();
    int high = m_scopeHigh.back();

    m_scopeStart.pop_back();
    m_scopeHigh.pop_back();

    m_nextOffset = start;

    if (!m_scopeHigh.empty() && high > m_scopeHigh.back())
    {
        m_scopeHigh.back() = high;
    }

    return high - start;
}

void cComputeSize::VisitAllNodes(cAstNode *node)
{
    if (node != nullptr)
    {
        node->Visit(this);
    }
}

// Default visit implementations
void cComputeSize::Visit(cAstNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cBlockNode *node)
{
    if (node != nullptr)
    {
        EnterScope();

        if (node->GetDecls() != nullptr) node->GetDecls()->Visit(this);
        if (node->GetStmts() != nullptr) node->GetStmts()->Visit(this);

        node->SetSize(LeaveScope());
    }
}

void cComputeSize::Visit(cDeclNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cDeclsNode *node)
{
    if (node != nullptr)
    {
        int start = m_nextOffset;

        for (int i = 0; i < node->NumDecls(); i++)
        {
            cDeclNode *decl = node->GetDecl(i);
            if (decl != nullptr) decl->Visit(this);
        }

        node->SetSize(m_nextOffset - start);
    }
}

void cComputeSize::Visit(cExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cIntExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cFloatExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cBinaryExprNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cVarDeclNode *node)
{
    if (node != nullptr)
    {
        cDeclNode *type = node->GetDeclaredTypeDecl();
        if (type == nullptr)
        {
            type = node->GetType();
        }
        int size = (type != nullptr) ? type->GetSize() : 0;
        int offset = AllocateLocal(size);

        node->SetSize(size);
        node->SetOffset(offset);

        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cStructDeclNode *node)
{
    if (node != nullptr)
    {
        int savedOffset = m_nextOffset;
        std::vector<int> savedStart = m_scopeStart;
        std::vector<int> savedHigh = m_scopeHigh;

        m_scopeStart.clear();
        m_scopeHigh.clear();
        m_nextOffset = 0;
        EnterScope();

        cDeclsNode *fields = node->GetDecls();
        if (fields != nullptr) fields->Visit(this);

        int structSize = LeaveScope();

        node->SetSize(structSize);
        node->SetOffset(0);

        m_nextOffset = savedOffset;
        m_scopeStart = savedStart;
        m_scopeHigh = savedHigh;

        cSymbol *name = node->GetSymbol();
        if (name != nullptr) name->Visit(this);
    }
}

void cComputeSize::Visit(cArrayDeclNode *node)
{
    if (node != nullptr)
    {
        cDeclNode *elemType = node->GetElementDecl();
        int elemSize = (elemType != nullptr) ? elemType->GetSize() : 0;

        node->SetSize(elemSize * node->GetCount());
        node->SetOffset(0);

        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cVarRefNode *node)
{
    if (node != nullptr)
    {
        node->ClearRowSizes();

        cDeclNode *decl = node->GetDecl();
        cDeclNode *curType = nullptr;
        int offset = 0;
        int baseSize = 0;
        bool hasArrayIndex = false;

        cVarDeclNode *varDecl = dynamic_cast<cVarDeclNode*>(decl);
        if (varDecl != nullptr)
        {
            curType = varDecl->GetDeclaredTypeDecl();
            offset = varDecl->GetOffset();
        }

        if (curType == nullptr && decl != nullptr)
        {
            curType = decl->GetType();
            offset = decl->GetOffset();
        }

        if (curType != nullptr)
        {
            baseSize = curType->GetSize();
        }

        for (int i = 0; i < node->NumParts(); i++)
        {
            cAstNode *part = node->GetPart(i);
            cExprNode *indexExpr = dynamic_cast<cExprNode*>(part);

            if (indexExpr != nullptr)
            {
                hasArrayIndex = true;

                if (curType != nullptr && curType->IsArray())
                {
                    cArrayDeclNode *arrayType = dynamic_cast<cArrayDeclNode*>(curType);
                    if (arrayType != nullptr)
                    {
                        curType = arrayType->GetElementDecl();
                    }
                    else
                    {
                        curType = curType->GetType();
                    }

                    if (curType != nullptr)
                    {
                        node->AddRowSize(curType->GetSize());
                    }
                }

                indexExpr->Visit(this);
            }
            else
            {
                cSymbol *field = dynamic_cast<cSymbol*>(part);
                if (field != nullptr)
                {
                    cDeclNode *fieldDecl = field->GetDecl();

                    if (fieldDecl == nullptr && curType != nullptr)
                    {
                        fieldDecl = FindStructField(curType, field->GetName());
                    }

                    if (fieldDecl != nullptr)
                    {
                        cVarDeclNode *fieldVar = dynamic_cast<cVarDeclNode*>(fieldDecl);
                        if (fieldVar != nullptr && fieldVar->GetSymbol() != nullptr)
                        {
                            node->SetPart(i, fieldVar->GetSymbol());
                        }

                        offset += fieldDecl->GetOffset();
                        curType = fieldDecl->GetType();
                    }
                }
            }
        }

        if (hasArrayIndex)
        {
            node->SetSize(baseSize);
        }
        else if (curType != nullptr)
        {
            node->SetSize(curType->GetSize());
        }
        node->SetOffset(offset);

        cSymbol *sym = node->GetSymbol();
        if (sym != nullptr) sym->Visit(this);
    }
}

void cComputeSize::Visit(cAssignNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cIfNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cWhileNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cReturnNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cPrintsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cArgsNode *node)
{
    if (node != nullptr)
    {
        int argOffset = m_protoArgs ? 0 : -12;
        int totalSize = 0;

        for (int i = 0; i < node->NumArgs(); i++)
        {
            cVarDeclNode *argDecl = dynamic_cast<cVarDeclNode*>(node->GetArg(i));
            if (argDecl == nullptr) continue;

            cDeclNode *type = argDecl->GetDeclaredTypeDecl();
            if (type == nullptr)
            {
                type = argDecl->GetType();
            }

            int size = (type != nullptr) ? type->GetSize() : 0;
            int slotSize = size;
            if (slotSize < WORD_SIZE) slotSize = WORD_SIZE;
            if (slotSize % WORD_SIZE != 0)
            {
                slotSize += (WORD_SIZE - (slotSize % WORD_SIZE));
            }

            argDecl->SetSize(size);
            argDecl->SetOffset(argOffset);
            if (m_protoArgs)
            {
                argOffset += slotSize;
            }
            else
            {
                argOffset -= slotSize;
            }
            totalSize += slotSize;

            argDecl->VisitAllChildren(this);
        }

        node->SetSize(totalSize);
    }
}

void cComputeSize::Visit(cParamsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cFuncDeclNode *node)
{
    if (node != nullptr)
    {
        node->SetOffset(0);

        cSymbol *retTypeSym = node->GetTypeSymbol();
        cSymbol *name = node->GetSymbol();
        if (retTypeSym != nullptr) retTypeSym->Visit(this);
        if (name != nullptr) name->Visit(this);

        cArgsNode *args = node->GetArgs();
        m_protoArgs = !node->IsFullyDefined();
        if (args != nullptr) args->Visit(this);
        m_protoArgs = false;

        if (!node->IsFullyDefined())
        {
            node->SetSize(args != nullptr ? args->GetSize() : 0);
            return;
        }

        int savedOffset = m_nextOffset;
        std::vector<int> savedStart = m_scopeStart;
        std::vector<int> savedHigh = m_scopeHigh;

        m_scopeStart.clear();
        m_scopeHigh.clear();
        m_nextOffset = 0;

        EnterScope();

        cDeclsNode *decls = node->GetDecls();
        cStmtsNode *stmts = node->GetStmts();
        if (decls != nullptr) decls->Visit(this);
        if (stmts != nullptr) stmts->Visit(this);

        int frameSize = LeaveScope();
        frameSize = AlignOffset(frameSize, WORD_SIZE);

        cDeclNode *retDecl = node->GetType();
        if (retDecl != nullptr && retDecl->GetSize() > frameSize)
        {
            frameSize = retDecl->GetSize();
        }

        node->SetSize(frameSize);

        m_nextOffset = savedOffset;
        m_scopeStart = savedStart;
        m_scopeHigh = savedHigh;
    }
}

void cComputeSize::Visit(cFuncCallNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);

        cParamsNode *params = node->GetParams();
        cDeclNode *retType = node->GetType();
        if (params != nullptr && retType != nullptr)
        {
            params->SetSize(retType->GetSize());
        }
    }
}

void cComputeSize::Visit(cOpNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cPrintNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cProgramNode *node)
{
    if (node != nullptr)
    {
        m_nextOffset = 0;
        m_scopeStart.clear();
        m_scopeHigh.clear();

        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cStmtNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cStmtsNode *node)
{
    if (node != nullptr)
    {
        node->VisitAllChildren(this);
    }
}

void cComputeSize::Visit(cSymbol *node)
{
    // Symbols don't have children
}
