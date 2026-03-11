//****************************************************
// cSymbolTable.cpp - Implementation of symbol table
//
#include <vector>
#include "cSymbolTable.h"
#include "cBaseTypeNode.h"

using std::vector;

// Internal structure to hold the nested scopes
static vector<symbolTable_t*> g_scopes;

// Global symbol table instance
cSymbolTable g_symbolTable;
cSymbolTable g_SymbolTable;  // Alias for compatibility

// Lexer control globals
int g_insert = 0;
int g_local = 0;

// Constructor
cSymbolTable::cSymbolTable()
{
    // Create the initial global scope
    if (g_scopes.empty())
    {
        g_scopes.push_back(new symbolTable_t());
    }
}

// Initialize the root symbol table with built-in types
void cSymbolTable::InitRootTable()
{
    // Preload built-in types to stabilize symbol IDs
    // Format: name, size, isFloat
    struct TypeInfo {
        const char *name;
        int size;
        bool isFloat;
    } types[] = {
        {"char", 1, false},
        {"int", 4, false},
        {"float", 8, true}
    };
    
    for (const auto &typeInfo : types)
    {
        cSymbol *sym = Find(typeInfo.name);
        if (sym == nullptr)
        {
            // Create the base type node
            cBaseTypeNode *typeNode = new cBaseTypeNode(
                typeInfo.name, 
                typeInfo.size, 
                typeInfo.isFloat
            );
            
            // Create the symbol and set its decl
            sym = new cSymbol(typeInfo.name);
            sym->SetDecl(typeNode);
            Insert(sym);
        }
    }
}

// Increase the scope: add a level to the nested symbol table
symbolTable_t *cSymbolTable::IncreaseScope()
{
    if (g_scopes.empty())
    {
        g_scopes.push_back(new symbolTable_t());
    }
    symbolTable_t *newScope = new symbolTable_t();
    g_scopes.push_back(newScope);
    return newScope;
}

// Decrease the scope: remove the outer-most scope
symbolTable_t *cSymbolTable::DecreaseScope()
{
    if (g_scopes.size() > 1)
    {
        g_scopes.pop_back();
    }
    
    if (g_scopes.size() > 0)
    {
        return g_scopes.back();
    }
    
    return nullptr;
}

// Insert a symbol into the table
void cSymbolTable::Insert(cSymbol *sym)
{
    if (g_scopes.empty())
    {
        g_scopes.push_back(new symbolTable_t());
    }
    if (g_scopes.size() > 0 && sym != nullptr)
    {
        (*g_scopes.back())[sym->GetName()] = sym;
    }
}

// Find a symbol in the nested table, starting from innermost scope
cSymbol *cSymbolTable::Find(string name)
{
    // Search from innermost scope (back) to outermost scope (front)
    for (int i = g_scopes.size() - 1; i >= 0; i--)
    {
        auto it = g_scopes[i]->find(name);
        if (it != g_scopes[i]->end())
        {
            return it->second;
        }
    }
    
    return nullptr;
}

// Find a symbol in the innermost scope only
cSymbol *cSymbolTable::FindLocal(string name)
{
    if (g_scopes.empty())
    {
        g_scopes.push_back(new symbolTable_t());
    }
    if (g_scopes.size() > 0)
    {
        auto it = g_scopes.back()->find(name);
        if (it != g_scopes.back()->end())
        {
            return it->second;
        }
    }
    return nullptr;
}
