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
#include "TransitionGraph.h"

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
};

typedef std::map<std::string, LexemType> ReservedWords;

class Lexer {
    private:
        istream&        input_;
        ReservedWords   reserved_words_;
        Token           token_;
        unsigned char   current_char_;
        TransitionGraph transitionGraph;
        string          tmp_char_buffer;

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

        unsigned char getNextChar() {
            unsigned char chr = input_.get();
            std::locale loc;
            chr = std::tolower(chr, loc);
            return chr;
        }

        void createTransitionGraph() {
            // Form an finite state machine
            State init_state("init_state", STATE_START); 
            // L_AUTOMATON LEXEM
            State automaton_a("automaton_a", STATE_ORDINARY);

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
