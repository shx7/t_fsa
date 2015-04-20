/**************************************************************
*
*   PURPOSE: Contrain control logic for adding new
*            lexems into Lexer.
*
**************************************************************/
#ifndef LEXER_CONTROL_COMMAND
#define LEXER_CONTROL_COMMAND
#include "SemanticCommand.h"
#include "CharacterAccumulateCommand.h"
#include "LexerTypes.h"
#include <iostream>

using namespace std;

class Lexer;

class LexerControlCommand : public SemanticCommand {
    private:
        Lexer           *lexer_;
        SemanticCommand *assotiatedCmd_;
        LexemType       assotiatedCmdType_;

    public:
        LexerControlCommand() : lexer_(NULL), assotiatedCmd_(NULL) {};
        void command(unsigned char input);
        void assotiateWithLexer(Lexer* lexer);
        void assotiateWithCommand(SemanticCommand* sem, LexemType type);
};
#endif
