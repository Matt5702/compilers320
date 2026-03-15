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
#include "cSemantics.h"
#include "cComputeSize.h"
#include "cCodeGen.h"
#include "cSymbol.h"

// Uncomment the following line after integrating your symbol table with
// your scanner.
long long cSymbol::nextId;

#define LAB5B
#define LAB6
#define LAB7

int main(int argc, char **argv)
{
    //std::cout << "Philip Howard" << std::endl;

    const char *outfile_name;
    int result = 0;
    //std::streambuf *cout_buf = std::cout.rdbuf();

    if (argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if (yyin == nullptr)
        {
            std::cerr << "ERROR: Unable to open file " << argv[1] << "\n";
            exit(-1);
        }
    }

    if (argc > 2)
    {
        outfile_name = argv[2];
    }
    else
    {
#ifdef LAB7
        outfile_name = "langout";
#else
        outfile_name = "/dev/tty";
#endif
    }

#ifndef LAB7
    FILE *output = fopen(outfile_name, "w");
    if (output == nullptr)
    {
        std::cerr << "Unable to open output file " << outfile_name << "\n";
        exit(-1);
    }

    // redirect stdout to the output file
    int output_fd = fileno(output);
    if (dup2(output_fd, 1) != 1)
    {
        std::cerr << "Unable to configure output stream\n";
        exit(-1);
    }
#endif

    g_SymbolTable.InitRootTable();

    result = yyparse();
    if (yyast_root != nullptr)
    {
#ifdef LAB5B
        cSemantics semantics;
        semantics.VisitAllNodes(yyast_root);
#endif

        result += yynerrs;
        if (result == 0)
        {
#if defined(LAB6) || defined(LAB7)
            cComputeSize sizer;
            sizer.VisitAllNodes(yyast_root);
#endif

#ifdef LAB7
            string filename(outfile_name);
            filename += ".sl";
            {
                cCodeGen coder(filename);
                coder.VisitAllNodes(yyast_root);
            }
#else
            std::cout << yyast_root->ToString() << std::endl;
#endif
        }
    }

    if (yynerrs != 0)
    {
        std::cout << yynerrs << " Errors in compile\n";
    }

    if (result == 0 && yylex() != 0)
    {
        std::cerr << "Junk at end of program\n";
    }

    return result;
}