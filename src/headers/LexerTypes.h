/**************************************************************
*
*   PURPOSE: Contains data types, used by Lexer
*
**************************************************************/
#ifndef LEXER_TYPES
#define LEXER_TYPES

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
};

#endif
