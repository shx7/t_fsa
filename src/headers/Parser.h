/**************************************************************
*
*   PURPOSE: Parser in an syntax analyzer
*
**************************************************************/
#ifdef PARSER_H
#define PARSER_H
#include "Lexer.h"
#include <iostream>

//#define PARSER_DEBUG

using namespace std;

class Parser {
    public:

    private:
        Lexer           lexer_;
        TransitionGraph transitionGraph_;
};

#endif
