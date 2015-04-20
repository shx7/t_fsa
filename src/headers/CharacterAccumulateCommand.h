/**************************************************************
*
*   PURPOSE: Semantic for Lexer automaton.
*
**************************************************************/
#ifndef CHARACTER_ACCUMULATOR_SEMANTIC_COMMAND
#define CHARACTER_ACCUMULATOR_SEMANTIC_COMMAND
#include "SemanticCommand.h"
#include <iostream>
#include <string>

using namespace std;

class CharacterAccumulateCommand : public SemanticCommand {
    private:
        string buffer;

    public:
        void command(unsigned char input);
        string getBuffer();
        void clearBuffer();
};
#endif
