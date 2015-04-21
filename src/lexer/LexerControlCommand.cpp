#include "LexerControlCommand.h"
#include "Lexer.h"

void LexerControlCommand::command(unsigned char input) {
    string str_token_data;
    Token token;

    switch (assotiatedCmdType_) {
        case L_IDENTIFIER:
            cout << "LexerControlCommand::command() LEXEM has been recognized! value:" << endl;
            cout << "\"" << ((CharacterAccumulateCommand *)(assotiatedCmd_))->getBuffer() << "\"" << endl;
            str_token_data = (((CharacterAccumulateCommand *)(assotiatedCmd_))->getBuffer());
            token.type_ = lexer_->parseLexemType(str_token_data);
            token.data_ = new string(str_token_data); // Potential memory leak
            lexer_->pushToken(token);
            ((CharacterAccumulateCommand *)(assotiatedCmd_))->clearBuffer();
            break;

        case L_OPEN_PARENTHESIS:
            cout << "LexerControlCommand::command() LEXEM has been recognized: L_OPEN_PARENTHESIS" << endl;
            token.type_ = L_OPEN_PARENTHESIS;
            lexer_->pushToken(token);
            break;

        case L_CLOSING_PARENTHESIS:
            cout << "LexerControlCommand::command() LEXEM has been recognized: L_CLOSING_PARENTHESIS" << endl;
            token.type_ = L_CLOSING_PARENTHESIS;
            lexer_->pushToken(token);
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
