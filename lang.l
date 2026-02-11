%{
//**************************************
// lang.l
//
// scanner definition file. flex uses this file to create the scanner
//
// Author: Matt Elfbrandt
//

// Illustration showing how to use {} to control scope
// NOTE: this is pseudo-code illustrating how you can adapt your current lang.l

#include <cstdlib>
#include <string>

#include "cSymbol.h"
#include "cSymbolTable.h"
#include "lex.h"
#include "langparse.h"

// Macros that can be used to create debug output from the scanner
// Uncomment the next line of code to generate debug output.
// Note: for this to work, use DO_RETURN(val) for all the return statements
//       for your tokens. See sample below for "program"
//#define DEBUG_OUTPUT
#ifdef DEBUG_OUTPUT
    #define DO_RETURN(a) { return Return(a); }
#else
    #define DO_RETURN(a) { return (a); }
#endif

int Return(int val);

static int ProcessID();
static int ProcessType();
static std::string UnquoteString(const char *text);
%}

%option noyywrap
%option noinput
%option nounput
%option yylineno

    /* definitions go here. whitespace is an example. */
whitespace      [ \t\n\r]+

%%

    /* Comments */
"//".*\n                  { /* ignore C++ style comments */ }

    /* Keywords */
program                   DO_RETURN(PROGRAM);
if                        DO_RETURN(IF);
else                      DO_RETURN(ELSE);
endif                     DO_RETURN(ENDIF);
while                     DO_RETURN(WHILE);
print                     DO_RETURN(PRINT);
char                      return ProcessType();
int                       return ProcessType();
long                      return ProcessType();
float                     return ProcessType();
double                    return ProcessType();
struct                    DO_RETURN(STRUCT);
array                     DO_RETURN(ARRAY);
return                    DO_RETURN(RETURN);
prints                    DO_RETURN(PRINTS);

    /* Multi-character operators */
"!="                      DO_RETURN(NOT_EQUALS);
"=="                      DO_RETURN(EQUALS);
"&&"                      DO_RETURN(AND);
"||"                      DO_RETURN(OR);
">="                      DO_RETURN(GE);
"<="                      DO_RETURN(LE);

    /* Literals */
[0-9]+                    { yylval.int_val = atoi(yytext); DO_RETURN(INT_VAL); }
[0-9]+\.[0-9]+            { yylval.float_val = strtod(yytext, nullptr); DO_RETURN(FLOAT_VAL); }
\"([^\\\"]|\\.)*\"        { yylval.str_val = new std::string(UnquoteString(yytext)); DO_RETURN(STRING_LIT); }

    /* Single character tokens */
"."                       DO_RETURN('.');
"("                       DO_RETURN('(');
")"                       DO_RETURN(')');
"{"                       DO_RETURN('{');
"}"                       DO_RETURN('}');
"["                       DO_RETURN('[');
"]"                       DO_RETURN(']');
","                       DO_RETURN(',');
";"                       DO_RETURN(';');
"+"                       DO_RETURN('+');
"-"                       DO_RETURN('-');
"*"                       DO_RETURN('*');
"/"                       DO_RETURN('/');
"%"                       DO_RETURN('%');
"="                       DO_RETURN('=');
">"                       DO_RETURN('>');
"<"                       DO_RETURN('<');

    /* Identifiers - must come after keywords */
[a-zA-Z_][a-zA-Z0-9_]*    { return ProcessID(); }

    /* Whitespace */
{whitespace}              { /* ignore */ }

    /* Catch-all */
.                         DO_RETURN(JUNK_TOKEN);

%%

//******************************************************
// ProcessID: create symbols in symbol table
static int ProcessID()
{
    std::string name(yytext);
    cSymbol *sym;

    if (g_insert)
    {
        sym = g_symbolTable.FindLocal(name);
        if (sym == nullptr)
        {
            sym = new cSymbol(name);
            g_symbolTable.Insert(sym);
        }
    }
    else
    {
        if (g_local)
            sym = g_symbolTable.FindLocal(name);
        else
            sym = g_symbolTable.Find(name);

        if (sym == nullptr)
            sym = new cSymbol(name);
    }
    yylval.symbol = sym;

    if (sym->IsType())
        return TYPE_ID;
    return IDENTIFIER;
}

// Create or reuse a symbol for built-in types
static int ProcessType()
{
    std::string name(yytext);
    cSymbol *sym = g_symbolTable.Find(name);

    if (sym == nullptr)
    {
        sym = new cSymbol(name);
        sym->SetIsType(true);
        g_symbolTable.Insert(sym);
    }

    yylval.symbol = sym;
    return TYPE_ID;
}

static std::string UnquoteString(const char *text)
{
    std::string raw(text);
    if (raw.size() >= 2 && raw.front() == '"' && raw.back() == '"')
    {
        return raw.substr(1, raw.size() - 2);
    }

    return raw;
}

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
