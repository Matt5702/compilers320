%{
//**************************************
// calc.l
//
// scanner definition file for calc. flex uses this file to create the scanner
//
// Author: Lab3 Scanner
//

#include "lex.h"
#include "tokens.h"

// Macros that can be used to create debug output from the scanner
// Uncomment the next line of code to generate debug output.
//#define DEBUG_OUTPUT
#ifdef DEBUG_OUTPUT
    #define DO_RETURN(a) { return Return(a); }
#else
    #define DO_RETURN(a) { return (a); }
#endif

int Return(int val);
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
char                      DO_RETURN(CHAR);
int                       DO_RETURN(INT);
long                      DO_RETURN(LONG);
float                     DO_RETURN(FLOAT);
double                    DO_RETURN(DOUBLE);
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
[0-9]+                    DO_RETURN(INT_VAL);
[0-9]+\.[0-9]+            DO_RETURN(FLOAT_VAL);
\"([^\\\"]|\\.)*\"        DO_RETURN(STRING_LIT);

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
[a-zA-Z_][a-zA-Z0-9_]*    DO_RETURN(IDENTIFIER);

    /* Whitespace */
{whitespace}              { /* ignore */ }

    /* Catch-all */
.                         DO_RETURN(JUNK_TOKEN);

%%

// This function allows us to do extra processing on each token
// It is used to generate lexer debug info
int Return(int val)
{
    printf("Scanned '%s': %d\n", yytext, val);
    return val;
}
