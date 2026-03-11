%{
//**************************************
// lang.y
//
// Parser definition file. bison uses this file to generate the parser.
//
// Author: Phil Howard 
//

#include <iostream>
#include "lex.h"
#include "astnodes.h"
#include "cSymbolTable.h"
#include "cBaseTypeNode.h"

%}

%locations

 /* union defines the type for lexical values */
%union{
    int             int_val;
    double          float_val;
    std::string*    str_val;
    cAstNode*       ast_node;
    cProgramNode*   program_node;
    cBlockNode*     block_node;
    cDeclsNode*     decls_node;
    cDeclNode*      decl_node;
    cStmtsNode*     stmts_node;
    cStmtNode*      stmt_node;
    cExprNode*      expr_node;
    cIntExprNode*   int_node;
    cFloatExprNode* float_node;
    cVarRefNode*    varref_node;
    cArgsNode*      args_node;
    cParamsNode*    params_node;
    cSymbol*        symbol;
    }

%{
    int yyerror(const char *msg);

    cAstNode *yyast_root;
    static cSymbol *g_declType = nullptr;
    static cSymbol *g_declName = nullptr;
    static cFuncDeclNode *g_funcDecl = nullptr;
    static bool g_semanticErrorHappened = false;
    
    // Error checking macros
    #define CHECK_ERROR() { if (g_semanticErrorHappened) \
        { g_semanticErrorHappened = false; } }
    #define PROP_ERROR() { if (g_semanticErrorHappened) \
        { g_semanticErrorHappened = false; YYERROR; } }
%}

%start  program

%token <symbol>    IDENTIFIER
%token <symbol>    TYPE_ID
%token <int_val>   CHAR_VAL
%token <int_val>   INT_VAL
%token <float_val> FLOAT_VAL
%token <int_val>   LE
%token <int_val>   GE
%token <int_val>   AND
%token <int_val>   OR
%token <int_val>   EQUALS
%token <int_val>   NOT_EQUALS
%token <str_val>   STRING_LIT

%token  PROGRAM
%token  PRINT PRINTS
%token  WHILE IF ELSE ENDIF
%token  STRUCT ARRAY
%token  RETURN
%token  JUNK_TOKEN

%type <program_node> program
%type <block_node> block
%type <block_node> func_body
%type <ast_node> open
%type <ast_node> close
%type <decls_node> decls
%type <decl_node> decl
%type <decl_node> var_decl
%type <decl_node> struct_decl
%type <decl_node> array_decl
%type <decl_node> decl_after_id
%type <ast_node> func_tail
%type <expr_node> func_call
%type <args_node> paramsspec
%type <decl_node> paramspec
%type <stmts_node> stmts
%type <stmt_node> stmt
%type <varref_node> lval
%type <params_node> params
%type <expr_node> param
%type <expr_node> expr
%type <expr_node> andexpr
%type <expr_node> eqexpr
%type <expr_node> relexpr
%type <expr_node> addit
%type <expr_node> term
%type <expr_node> fact
%type <varref_node> varref
%type <symbol> varpart

%%

program: PROGRAM block
                                { $$ = new cProgramNode($2);
                                  yyast_root = $$;
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
    |   block
                                { $$ = new cProgramNode($1);
                                  yyast_root = $$;
                                  if (yynerrs == 0)
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
block:  open decls stmts close
                                { $$ = new cBlockNode($2, $3); }
    |   open stmts close
                                { $$ = new cBlockNode(nullptr, $2); }

func_body: block
                                { $$ = $1; }

open:   '{'
                                { g_symbolTable.IncreaseScope(); }

close:  '}'
                                { g_symbolTable.DecreaseScope(); }

decls:      decls decl
                                { $1->Insert($2); $$ = $1; }
        |   decl
                                { $$ = new cDeclsNode($1); }
decl:       TYPE_ID { g_insert = 1; } IDENTIFIER { g_insert = 0; g_declType = $1; g_declName = $3; } decl_after_id
                { $$ = $5; }
    |   array_decl ';'
                                { $$ = $1; }
        |   struct_decl ';'
                                { $$ = $1; }
        |   error ';'
                                { $$ = nullptr; }

var_decl:   TYPE_ID { g_insert = 1; } IDENTIFIER
                                    {
                                        g_insert = 0;
                                        cVarDeclNode *varDecl = new cVarDeclNode($1, $3);
                                        $3->SetDecl(varDecl);
                                        $$ = varDecl;
                                    }
struct_decl:  STRUCT open decls close { g_insert = 1; } IDENTIFIER
                                { 
                                    g_insert = 0;
                                    cStructDeclNode *structNode = new cStructDeclNode($3, $6);
                                    $6->SetDecl(structNode);
                                    $$ = structNode;
                                }
array_decl:   ARRAY TYPE_ID '[' INT_VAL ']' { g_insert = 1; } IDENTIFIER
                                { 
                                    g_insert = 0;
                                    cArrayDeclNode *arrayNode = new cArrayDeclNode($2, $7, $4);
                                    $7->SetDecl(arrayNode);
                                    $$ = arrayNode;
                                }

decl_after_id: ';'
                                                                {
                                                                    cVarDeclNode *varDecl = new cVarDeclNode(g_declType, g_declName);
                                                                    g_declName->SetDecl(varDecl);
                                                                    $$ = varDecl;
                                                                }
                |   '(' { g_symbolTable.IncreaseScope(); } paramsspec ')'
                                                                {
                                                                    g_funcDecl = new cFuncDeclNode(g_declType, g_declName, $3);
                                                                    g_declName->SetDecl(g_funcDecl);
                                                                }
                    func_tail
                                                                { g_symbolTable.DecreaseScope(); $$ = g_funcDecl; g_funcDecl = nullptr; }
                |   '(' { g_symbolTable.IncreaseScope(); } ')'
                                                                {
                                                                    g_funcDecl = new cFuncDeclNode(g_declType, g_declName, nullptr);
                                                                    g_declName->SetDecl(g_funcDecl);
                                                                }
                    func_tail
                                                                { g_symbolTable.DecreaseScope(); $$ = g_funcDecl; g_funcDecl = nullptr; }

func_tail: ';'
                                                                { $$ = nullptr; }
                |   func_body
                                                                { if (g_funcDecl != nullptr)
                                                                  {
                                                                      if ($1->GetDecls() != nullptr)
                                                                          g_funcDecl->AppendDecls($1->GetDecls());
                                                                      g_funcDecl->AppendStmts($1->GetStmts());
                                                                  }
                                                                  $$ = nullptr; }
paramsspec:  paramsspec ',' paramspec
                                { $1->Insert($3); $$ = $1; }
        |   paramspec
                                { $$ = new cArgsNode($1); }

paramspec:  var_decl
                                    { $$ = $1; }

stmts:      stmts stmt
                                { $1->Insert($2); $$ = $1; }
        |   stmt
                                { $$ = new cStmtsNode($1); }

stmt:       IF '(' expr ')' stmts ENDIF ';'
                                { $$ = new cIfNode($3, $5, nullptr); }
        |   IF '(' expr ')' stmts ELSE stmts ENDIF ';'
                                { $$ = new cIfNode($3, $5, $7); }
        |   WHILE '(' expr ')' stmt
                                { $$ = new cWhileNode($3, $5); }
        |   PRINT '(' expr ')' ';'
                                { $$ = new cPrintNode($3); }
        |   PRINTS '(' STRING_LIT ')' ';'
                                { $$ = new cPrintsNode(*$3); delete $3; }
        |   lval '=' expr ';'
                                { $$ = new cAssignNode($1, $3); }
        |   func_call ';'
                    { $$ = $1; }
        |   block
                                { $$ = $1; }
        |   RETURN expr ';'
                                { $$ = new cReturnNode($2); }
        |   error ';'
                                { $$ = nullptr; }

func_call:  IDENTIFIER '(' params ')'
                                    { $$ = new cFuncCallNode($1, $3); }
        |   IDENTIFIER '(' ')'
                            { $$ = new cFuncCallNode($1, nullptr); }

varref:   varref '.' varpart
                                { $1->AddPart($3); $$ = $1; }
        | varref '[' expr ']'
                                { $1->AddPart($3); $$ = $1; }
        | varpart
                                { $$ = new cVarRefNode($1); }

varpart:  IDENTIFIER
                                { $$ = $1; }

lval:     varref
                                { $$ = $1; }

params:   params ',' param
                                { $1->Insert($3); $$ = $1; }
        |   param
                                { $$ = new cParamsNode($1); }

param:      expr
                                { $$ = $1; }

expr:       expr OR andexpr
                { $$ = new cBinaryExprNode($1, new cOpNode(OR), $3); }
    |   andexpr
                                { $$ = $1; }

andexpr:    andexpr AND eqexpr
                { $$ = new cBinaryExprNode($1, new cOpNode(AND), $3); }
    |   eqexpr
                { $$ = $1; }

eqexpr:     eqexpr EQUALS relexpr
                { $$ = new cBinaryExprNode($1, new cOpNode(EQUALS), $3); }
    |   eqexpr NOT_EQUALS relexpr
                { $$ = new cBinaryExprNode($1, new cOpNode(NOT_EQUALS), $3); }
    |   relexpr
                { $$ = $1; }

relexpr:    relexpr '>' addit
                { $$ = new cBinaryExprNode($1, new cOpNode('>'), $3); }
    |   relexpr '<' addit
                { $$ = new cBinaryExprNode($1, new cOpNode('<'), $3); }
    |   relexpr GE addit
                { $$ = new cBinaryExprNode($1, new cOpNode(GE), $3); }
    |   relexpr LE addit
                { $$ = new cBinaryExprNode($1, new cOpNode(LE), $3); }
    |   addit
                { $$ = $1; }

addit:      addit '+' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('+'), $3); }
        |   addit '-' term
                                { $$ = new cBinaryExprNode($1, new cOpNode('-'), $3); }
        |   term
                                { $$ = $1; }

term:       term '*' fact
                                { $$ = new cBinaryExprNode($1, new cOpNode('*'), $3); }
        |   term '/' fact
                                { $$ = new cBinaryExprNode($1, new cOpNode('/'), $3); }
        |   term '%' fact
                                { $$ = new cBinaryExprNode($1, new cOpNode('%'), $3); }
        |   fact
                                { $$ = $1; }

fact:       '(' expr ')'
                                { $$ = $2; }
    |   '-' fact
                { $$ = new cBinaryExprNode(new cIntExprNode(0), new cOpNode('-'), $2); }
        |   INT_VAL
                                { $$ = new cIntExprNode($1); }
    |   CHAR_VAL
                { $$ = new cIntExprNode($1); }
        |   FLOAT_VAL
                                { $$ = new cFloatExprNode($1); }
        |   varref
                                { $$ = $1; }
        |   func_call
                                { $$ = $1; }

%%

// Function to format error messages
int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}

// Function that gets called when a semantic error happens
void SemanticParseError(std::string error)
{
    std::cout << "ERROR: " << error << " near line " 
              << yylineno << "\n";
    g_semanticErrorHappened = true;
    yynerrs++;
}
