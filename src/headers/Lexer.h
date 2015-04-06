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

#define DEFINE_STATE(name, type) \
    State name (#name, type);

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
            State start_st("start_st", STATE_START); 

            // Any word. Will be preprocessed later
            State word_st("word_st", STATE_ORDINARY);
            transitionGraph.addTransitionByPredicat(start_st, P_CHARACTER, word_st);
            transitionGraph.addTransitionByPredicat(word_st, P_CHARACTER, word_st);
            transitionGraph.addTransitionByPredicat(word_st, P_DIGIT, word_st);
            transitionGraph.addTransitionByPredicat(word_st, P_WHITE, start_st);

            // L_OPEN_PARENTETHIS lexem
            State opt_st("opt_st", STATE_ORDINARY);
            transitionGraph.addTransition(start_st, '}', opt_st);
            transitionGraph.addTransitionByPredicat(opt_st, P_WHITE, start_st);

            // L_CLOSING_PARENTHESIS lexem
            State cpt_st("cpt_st", STATE_ORDINARY);
            transitionGraph.addTransition(start_st, '{', cpt_st);
            transitionGraph.addTransitionByPredicat(cpt_st, P_WHITE, start_st);

            // L_TRANSITION lexem
            State trans_st1("trans_st1", STATE_ORDINARY);
            State trans_st2("trans_st2", STATE_ORDINARY);
            transitionGraph.addTransition(start_st, '=', trans_st1);
            transitionGraph.addTransition(trans_st1, '>', trans_st2);
            transitionGraph.addTransitionByPredicat(trans_st2, P_WHITE, start_st);

            // L_SEMICOLON lexem

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
