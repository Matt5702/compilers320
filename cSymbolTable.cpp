//****************************************************
// cSymbolTable.cpp - Implementation of symbol table
//
#include <vector>
#include "cSymbolTable.h"

using std::vector;

// Internal structure to hold the nested scopes
static vector<symbolTable_t*> g_scopes;

// Constructor
cSymbolTable::cSymbolTable()
{
    // Create the initial global scope
    if (g_scopes.empty())
    {
        g_scopes.push_back(new symbolTable_t());
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
