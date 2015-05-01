/**************************************************************
*
*   PURPOSE: Contains data types, used by Lexer
*
**************************************************************/
#ifndef LEXER_TYPES
#define LEXER_TYPES
#include <iostream>
//#define TOKEN_DEBUG

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
    #ifdef TOKEN_DEBUG
        cout << "Token::print() type:" << endl;
    #endif
        switch(type_) {
            case L_IDENTIFIER:
                cout << "L_IDENTIFIER" << endl;
                cout << "data_:\"" << *((string *)(data_)) << "\"" << endl;
                break;

            case L_AUTOMATON:
                cout << "L_AUTOMATON" << endl;
                cout << "data_:\"" << *((string *)(data_)) << "\"" << endl;
                break; 

            case L_CHAR:
                cout << "L_CHAR" << endl;
                cout << "data_:\"" << (*(char *)(data_)) << "\"" << endl;
                break; 

            case L_SEMICOLON:
                cout << "L_SEMICOLON" << endl;
                break; 

            case L_TRANSITION:
                cout << "L_TRANSITION" << endl;
                break; 

            case L_OPEN_PARENTHESIS:
                cout << "L_OPEN_PARENTHESIS" << endl;
                break; 

            case L_CLOSING_PARENTHESIS:
                cout << "L_CLOSING_PARENTHESIS" << endl;
                break; 

            case L_START:
                cout << "L_START" << endl;
                break; 

            case L_FINAL:
                cout << "L_FINAL" << endl;
                break; 

            case L_STATE:
                cout << "L_STATE" << endl;
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
