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

            // Parse L_IDENTIFIER or another reserved word
            token.type_ = lexer_->parseLexemType(str_token_data);
            token.data_ = new string(str_token_data); // Potential memory leak
            lexer_->pushToken(token);
            ((CharacterAccumulateCommand *)(assotiatedCmd_))->clearBuffer();

            // Check for L_SEMICOLON 
            if (input == ';') { 
                cout << "LexerControlCommand::command() LEXEM has been L_IDENTIFIER + L_SEMICOLON" << endl;
                token.type_ = L_SEMICOLON;
                lexer_->pushToken(token);
            }

            // Check for L_OPEN_PARENTHESIS
            if (input == '{') { 
                cout << "LexerControlCommand::command() LEXEM has been L_IDENTIFIER + L_OPEN_PARENTHESIS" << endl;
                token.type_ = L_OPEN_PARENTHESIS;
                lexer_->pushToken(token);
            } 
            break;

        case L_CHAR:
            cout << "LexerControlCommand::command() LEXEM has been recognized: L_CHAR, value:" << endl;
            str_token_data = (((CharacterAccumulateCommand *)(assotiatedCmd_))->getBuffer());
            cout << "\'" << str_token_data << "\'" << endl;

            token.type_ = L_CHAR;
            token.data_ = new char[1];
            *((char *)(token.data_)) = str_token_data.front();
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

        case L_TRANSITION:
            cout << "LexerControlCommand::command() LEXEM has been recognized: L_TRANSITION" << endl;
            token.type_ = L_TRANSITION;
            lexer_->pushToken(token);
            break;

        case L_SEMICOLON:
            cout << "LexerControlCommand::command() LEXEM has been recognized: L_SEMICOLON" << endl;
            token.type_ = L_SEMICOLON;
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
