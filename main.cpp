//**************************************
// main.cpp
//
// Main routine for lang compiler.
// This version only runs the lexer
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 23, 2015
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fstream>

#include "lex.h"
#include "astnodes.h"
#include "langparse.h"
#include "cSymbolTable.h"

// Uncomment the following line after integrating your symbol table with
// your scanner.
long long cSymbol::nextId;

// **************************************************
// argv[1] is the input file
// argv[2] if present, is the output file
int main(int argc, char **argv)
{
    const char *outfile_name;
    int result = 0;

    // Preload built-in types to stabilize symbol IDs
    const char *builtins[] = {"char", "int", "float", "long", "double"};
    for (const char *name : builtins)
    {
        cSymbol *sym = g_symbolTable.Find(name);
        if (sym == nullptr)
        {
            sym = new cSymbol(name);
            sym->SetIsType(true);
            g_symbolTable.Insert(sym);
        }
    }

    // open input
    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            std::cerr << "Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    // open output
    if (argc > 2)
    {
        outfile_name = argv[2];
        FILE *output = fopen(outfile_name, "w");
        if (output == NULL)
        {
            std::cerr << "Unable to open output file " << outfile_name << "\n";
            exit(-1);
        }
        int output_fd = fileno(output);
        if (dup2(output_fd, 1) != 1)
        {
            std::cerr << "Unable to send output to " << outfile_name << "\n";
            exit(-2);
        }
    }

    result = yyparse();
    if (yyast_root != nullptr)
    {
        if (result == 0)
        {
            std::cout << "<?xml version=\"1.0\"?>\n";
            std::cout << yyast_root->ToString();
        } else {
            std::cout << " Errors in compile\n";
        }
    }

    if (result == 0 && yylex() != 0)
    {
        std::cout << "Junk at end of program\n";
    }

    return result;
}
