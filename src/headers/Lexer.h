/*********************************************************
*
*   PURPOSE: Lexer used to create lexem flow from plain
*            text. Lexem - is the smallest syntactic 
*            unit, used for following syntax spell-check
*            and generation of automaton matrix
*
*********************************************************/
#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <map>
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

struct Lexem {
    LexemType type_;
};

struct Token {
    LexemType type_;
    string data_;
};

typedef std::map<std::string, LexemType> ReservedWords;

class Lexer {
    private:
        istream& input_;
        char current_char_;
        Token token_;
        ReservedWords reserved_words_;

    public:
        explicit Lexer(istream& input) : input_(input), current_char_(0) {
            cout << "Lexer constructed" << endl;
            initReservedWords();
        }

        Token& getNextToken();

    private: 
        void skipSubstractedChars() {
            cout << "SkippingSubstracted" << endl;
            current_char_ = getNextChar();
            cout << "Next chr: '" << current_char_ << "'" << endl;
            while ((current_char_ == ' ') || (current_char_ == '\t') || (current_char_ == '\n')) {
                cout << "substracted chr: '" << current_char_ << "'" << endl;
                current_char_ = getNextChar();
            }
        }

        char getNextChar() {
            return input_.get();
        }

        bool isBody(char chr) {
            std::locale loc;
            chr = std::tolower(chr, loc);
            if ((chr >= 'a') && (chr <= 'z')) {
                return true;
            }
            return false;
        }

        bool isDigit(char chr) {
            return ((chr >= '0') && (chr <= '9'));
        }

        bool isReservedWord(string& str) {
            ReservedWords::iterator itr;
            itr = reserved_words_.find(str);
            return (itr == reserved_words_.end());
        }

        void initReservedWords() {
            reserved_words_["automata"] = L_AUTOMATON;
            reserved_words_["state"] = L_STATE;
            reserved_words_["final"] = L_FINAL;
            reserved_words_["start"] = L_START;
            reserved_words_["start"] = L_START;
            reserved_words_["{"] = L_OPEN_PARENTHESIS;
            reserved_words_["}"] = L_CLOSING_PARENTHESIS;
            reserved_words_["=>"] = L_TRANSITION;
            reserved_words_[";"] = L_SEMICOLON;
        }

        bool match(LexemType) {
            return false;
        } 
};


#endif
