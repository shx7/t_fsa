#include "Lexer.h"

Token& Lexer::getNextToken() {
    string tmp;
    skipSubstractedChars();

    token_.type_ = L_ILLEGAL;

    // Checking for
    // L_AUTOMATON
    {
    }

    // Checking for
    // L_IDENTIFIER
    {
        if (isBody(current_char_)) {
            tmp += current_char_;

            while(isBody(current_char_)) {
                tmp += current_char_;
            }

            // If reserved word
            if (isReservedWord(tmp)) {
                token_.type_ = reserved_words_[tmp];
            } else {
                // Else variable
                token_.type_ = L_IDENTIFIER;
                token_.data_ = tmp;
            }
            return token_; 
        }
    }

    // Checking for 
    // L_TRANSITION
    {
        if (current_char_ == '=') {
            getNextChar();
            if (current_char_ == '>') {
                token_.type_ = L_TRANSITION;
                return token_;
            }
            return token_;
        }
    }

    // Checking for 
    // L_SEMICOLON
    {
        if (current_char_ == ';') {
            token_.type_ = L_SEMICOLON;
            return token_;
        }
    }

    // Checking for 
    // L_OPEN_PARENTHESIS
    {
        if (current_char_ == '{') {
            token_.type_ = L_OPEN_PARENTHESIS;
            return token_;
        }
    }

    // Checking for 
    // L_CLOSING_PARENTHESIS
    {
        if (current_char_ == '}') {
            token_.type_ = L_CLOSING_PARENTHESIS;
            return token_;
        }
    }

    return token_;
}
