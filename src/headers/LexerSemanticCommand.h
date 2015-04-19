/**************************************************************
*
*   PURPOSE: Contains logic for semantic in lexer automaton
*
**************************************************************/
#ifndef LEXER_SEMANTIC_COMMAND
#define LEXER_SEMANTIC_COMMAND
#include "SemanticCommand.h"
#include <iostream>

using namespace std;

class LexerSemanticCommand : public SemanticCommand {
    public:
        void command(unsigned char input);
};
#endif
