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
        Parser() : error_(false) {};


    private:
        Lexer           lexer_;
        TransitionGraph transitionGraph_;
        bool            error_;

        bool see(LexemType lexem);

        bool mustBe(LexemType lexem);

        void reportError(string error_str);
};

#endif
