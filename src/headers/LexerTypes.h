/**************************************************************
*
*   PURPOSE: Contains data types, used by Lexer
*
**************************************************************/
#ifndef LEXER_TYPES
#define LEXER_TYPES
#include <iostream>

using namespace std;

enum LexemType {
    L_AUTOMATON,
    L_STATE,
    L_FINAL,
    L_START,
    L_OPEN_PARENTHESIS,
    L_CLOSING_PARENTHESIS,
    L_TRANSITION,
    L_SEMICOLON,
    L_IDENTIFIER,
    L_CHAR,
    L_ILLEGAL,
    L_NOT_RECOGNIZED,
};

struct Token {
    LexemType type_;
    void      *data_;

    Token() : type_(L_ILLEGAL), data_(NULL) {}; 

    void print() {
        cout << "Token::print() type_:" << endl;
        switch(type_) {
            case L_IDENTIFIER:
                cout << "L_IDENTIFIER" << endl;
                cout << "data_:\"" << *((string *)(data_)) << "\"" << endl;
                break;

            case L_ILLEGAL:
                cout << "L_ILLEGAL" << endl;
                break;

            default:
                cout << "default val. Not impl." << endl;
        }
    }
};

#endif
