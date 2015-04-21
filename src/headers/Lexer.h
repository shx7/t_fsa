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
#include "LexerTypes.h"
#include "TransitionGraph.h"
#include "CharacterAccumulateCommand.h"
#include "LexerControlCommand.h"
#include "Engine.h"

#define LEXER_DEBUG

#define DEFINE_STATE(name, type) \
    State name (#name, type);

#define ADD_TRANSITION(st1, chr, st2) \
    transitionGraph.addTransition(st1, chr, st2);

#define ADD_TRANSITION_P(st1, predicat, st2) \
    transitionGraph.addTransitionByPredicat(st1, predicat, st2); 

#define ADD_TRANSITION_SEM(st1, chr, st2, sem_fun) \
    transitionGraph.addTransition(st1, chr, st2, sem_fun);

#define ADD_TRANSITION_SEM_P(st1, predicat, st2, sem_fun) \
    transitionGraph.addTransitionByPredicat(st1, predicat, st2, sem_fun); 

using namespace std;

typedef std::map<std::string, LexemType> ReservedWords;
typedef std::vector<Token> TokenContainer;

class Lexer {
    private:
        istream&             input_;
        ReservedWords        reserved_words_;
        Token                token_;
        TokenContainer       tokenContainer_;
        unsigned char        current_char_;
        TransitionGraph      transitionGraph;
        string               tmp_char_buffer;

        // Semantics cmd
        friend LexerControlCommand;
        CharacterAccumulateCommand characterAccumulateCmd;
        LexerControlCommand        lexerWordControlCmd;

    public:
        explicit Lexer(istream& input) : input_(input), current_char_(0) {
            cout << "Lexer constructed" << endl;
            initReservedWords();
            createTransitionGraph();
        }

        Token& getNextToken();

        void runParse() {
            // Run test
            InputSequence input;
            input.push_back('a');
            input.push_back('S');
            input.push_back(' ');
            input.push_back('s');
            input.push_back('a');
            input.push_back('k');
            input.push_back(0); 

            Engine engine; 
            EngineReport report = engine.run(transitionGraph, input);
            report.print();
        #ifdef LEXER_DEBUG
            printTokenContainer();
        #endif 
        }

    private: 

        void pushToken(Token& token) {
        #ifdef LEXER_DEBUG 
            cout << "Lexer::pushToken()" << endl; 
        #endif
            tokenContainer_.push_back(token);
        }

        #ifdef LEXER_DEBUG
        void printTokenContainer() {
            TokenContainer::iterator itr;
            for (itr = tokenContainer_.begin(); itr != tokenContainer_.end(); itr++) {
                (*itr).print();
            }
        }
        #endif

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
            DEFINE_STATE(start_st, STATE_START);

            // Any word. Will be preprocessed later
            DEFINE_STATE(word_st, STATE_ORDINARY);
            ADD_TRANSITION_SEM_P(start_st, P_CHARACTER, word_st, characterAccumulateCmd);
            ADD_TRANSITION_SEM_P(word_st, P_CHARACTER, word_st, characterAccumulateCmd);
            ADD_TRANSITION_SEM_P(word_st, P_DIGIT, word_st, characterAccumulateCmd);
            lexerWordControlCmd.assotiateWithLexer(this);
            lexerWordControlCmd.assotiateWithCommand(&characterAccumulateCmd, L_IDENTIFIER);
            ADD_TRANSITION_SEM_P(word_st, P_WHITE, start_st, lexerWordControlCmd);

            // L_OPEN_PARENTETHIS lexem
            DEFINE_STATE(opt_st, STATE_ORDINARY);
            ADD_TRANSITION(start_st, '{', opt_st);
            ADD_TRANSITION_P(opt_st, P_WHITE, start_st);

            // L_CLOSING_PARENTHESIS lexem
            DEFINE_STATE(cpt_st, STATE_ORDINARY);
            ADD_TRANSITION(start_st, '}', cpt_st);
            ADD_TRANSITION_P(cpt_st, P_WHITE, start_st);

            // L_TRANSITION lexem
            DEFINE_STATE(trans_st1, STATE_ORDINARY);
            DEFINE_STATE(trans_st2, STATE_ORDINARY);
            ADD_TRANSITION(start_st, '=', trans_st1);
            ADD_TRANSITION(trans_st1, '=', trans_st2);
            ADD_TRANSITION_P(trans_st2, P_WHITE, start_st);
            
            // L_SEMICOLON lexem
            DEFINE_STATE(semicolon_st, STATE_ORDINARY);
            ADD_TRANSITION(start_st, ';', semicolon_st); 
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
