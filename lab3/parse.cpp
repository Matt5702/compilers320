//**************************************
// parse.cpp
//
// Recursive descent parser for calc language
// Used in CST 320 Lab3
//
// Author: Phil Howard 
// phil.howard@oit.edu
//

#include <iostream>
#include "lex.h"
#include "parse.h"
#include "utils.h"
#include "tokens.h"

//*******************************************
// Find a PROG non-terminal
// PROG → STMTS 'end'
bool FindPROG()
{
    if (!FindSTMTS())
    {
        return false;
    }

    // No need to check for 'end' - just check for end of input
    return true;
}

//*******************************************
// Find STMTS non-terminal
// STMTS → STMT STMTS | λ
bool FindSTMTS()
{
    int token = PeekToken();
    
    // Check for end of statements (end of file)
    if (token == 0)
    {
        return true;
    }

    // Try to find a statement
    if (!FindSTMT())
    {
        // Error recovery: skip tokens until we find a semicolon or EOF
        while (token != 0 && token != ';')
        {
            AdvanceToken();
            token = PeekToken();
        }
        
        // If we found a semicolon, skip it and continue
        if (token == ';')
        {
            AdvanceToken();
        }
    }
    
    // Recursively find more statements
    return FindSTMTS();
}

//*******************************************
// Find a STMT non-terminal
// STMT → EXPR ';'
//     → identifier = EXPR ';'
bool FindSTMT()
{
    int token = PeekToken();
    
    // Check for assignment statement
    if (token == IDENTIFIER)
    {
        AdvanceToken();  // past identifier
        
        token = PeekToken();
        if (token == '=')
        {
            AdvanceToken();  // past '='
            
            if (!FindEXPR())
            {
                return false;
            }
            
            token = PeekToken();
            if (token != ';')
            {
                Error("';'");
                return false;
            }
            AdvanceToken();  // past ';'
            
            std::cout << "Found a statement\n";
            return true;
        }
        else
        {
            // Not an assignment, put token back
            UngetToken(IDENTIFIER);
        }
    }
    
    // Regular expression statement
    if (!FindEXPR())
    {
        return false;
    }

    token = PeekToken();
    if (token != ';')
    {
        Error("';'");
        return false;
    }
    AdvanceToken();  // past ';'

    std::cout << "Found a statement\n";
    return true;
}

//*******************************************
// Find EXPR non-terminal
// EXPR → (EXPR) EXPR'
//     → TERM
bool FindEXPR()
{
    int token = PeekToken();
    
    if (token == '(')
    {
        AdvanceToken();  // past '('
        
        if (!FindEXPR())
        {
            return false;
        }
        
        token = PeekToken();
        if (token != ')')
        {
            Error("')'");
            return false;
        }
        AdvanceToken();  // past ')'
        
        return FindEXPR_P();
    }
    else
    {
        return FindTERM();
    }
}

//*******************************************
// Find EXPR_P non-terminal
// EXPR' → PLUSOP (EXPR) EXPR'
//      → λ
bool FindEXPR_P()
{
    if (FindPLUSOP())
    {
        int token = PeekToken();
        if (token != '(')
        {
            Error("'('");
            return false;
        }
        AdvanceToken();  // past '('
        
        if (!FindEXPR())
        {
            return false;
        }
        
        token = PeekToken();
        if (token != ')')
        {
            Error("')'");
            return false;
        }
        AdvanceToken();  // past ')'
        
        return FindEXPR_P();
    }

    // λ production
    return true;
}

//*******************************************
// Find PLUSOP non-terminal
// PLUSOP → '+' | '-'
bool FindPLUSOP()
{
    int token = PeekToken();
    
    if (token == '+' || token == '-')
    {
        AdvanceToken();
        return true;
    }

    return false;
}

//*******************************************
// Find TERM non-terminal
// TERM → [EXPR] TERM'
//     → num
//     → { identifier }
bool FindTERM()
{
    int token = PeekToken();

    if (token == '[')
    {
        AdvanceToken();  // past '['
        
        if (!FindEXPR())
        {
            return false;
        }

        token = PeekToken();
        if (token != ']')
        {
            Error("']'");
            return false;
        }
        AdvanceToken();  // past ']'
        
        return FindTERM_P();
    }
    else if (token == INT_VAL)
    {
        AdvanceToken();  // past num
        return true;
    }
    else if (token == '{')
    {
        AdvanceToken();  // past '{'
        
        token = PeekToken();
        if (token != IDENTIFIER)
        {
            Error("identifier");
            return false;
        }
        AdvanceToken();  // past identifier
        
        token = PeekToken();
        if (token != '}')
        {
            Error("'}'");
            return false;
        }
        AdvanceToken();  // past '}'
        
        return true;
    }
    else
    {
        Error("'[', number, or '{'");
        return false;
    }
}

//*******************************************
// Find TERM_P non-terminal
// TERM' → TIMESOP [EXPR] TERM'
//      → λ
bool FindTERM_P()
{
    if (FindTIMESOP())
    {
        int token = PeekToken();
        if (token != '[')
        {
            Error("'['");
            return false;
        }
        AdvanceToken();  // past '['
        
        if (!FindEXPR())
        {
            return false;
        }
        
        token = PeekToken();
        if (token != ']')
        {
            Error("']'");
            return false;
        }
        AdvanceToken();  // past ']'
        
        return FindTERM_P();
    }

    // λ production
    return true;
}

//*******************************************
// Find TIMESOP non-terminal
// TIMESOP → '*' | '/'
bool FindTIMESOP()
{
    int token = PeekToken();
    
    if (token == '*' || token == '/')
    {
        AdvanceToken();
        return true;
    }

    return false;
}

//*******************************************
// Find FACTOR non-terminal (no longer used in this grammar)
bool FindFACTOR()
{
    Error("FACTOR not used in this grammar");
    return false;
}

