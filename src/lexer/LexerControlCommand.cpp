#include "LexerControlCommand.h"

void LexerControlCommand::command(unsigned char input) {
    switch (assotiatedCmdType_) {
        case L_IDENTIFIER:
            cout << "LexerControlCommand::command() LEXEM has been recognized! value:" << endl;
            cout << "\"" << ((CharacterAccumulateCommand *)(assotiatedCmd_))->getBuffer() << "\"" << endl;
            break;

        default:
            cerr << "LexerControlCommand::command() ERROR: unknown LexemType" << endl;
    }
}

void LexerControlCommand::assotiateWithLexer(Lexer* lexer) {
    lexer_ = lexer;
}

void LexerControlCommand::assotiateWithCommand(SemanticCommand* sem, LexemType type) {
    assotiatedCmd_ = sem;
    assotiatedCmdType_ = type;
} 
