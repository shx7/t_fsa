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
        LexerControlCommand        wordCtrlCmd;               // L_IDENTIFIER or all reserved words
        LexerControlCommand        openParenthesisCtrlCmd;    // L_OPEN_PARENTHESIS
        LexerControlCommand        closingParenthesisCtrlCmd; // L_CLOSING_PARENTHESIS
        LexerControlCommand        transitionCtrlCmd;         // L_TRANSITION
        LexerControlCommand        semicolonCtrlCmd;          // L_SEMICOLON
        LexerControlCommand        charCtrlCmd;               // L_CHAR
        NullSemanticCommand        nullCmd;

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
            input_ >> std::noskipws;
            while (!input_.eof()) {
                char chr;
                input_ >> chr;
                input.push_back(chr);
            } 
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
            ADD_TRANSITION_P(start_st, P_WHITE, start_st);

            cout << "Lexer::createTransitionGraph() add any word" << endl;
            // Any word. Will be preprocessed later
            wordCtrlCmd.assotiateWithLexer(this);
            wordCtrlCmd.assotiateWithCommand(&characterAccumulateCmd, L_IDENTIFIER);
            DEFINE_STATE(word_st, STATE_ORDINARY);
            ADD_TRANSITION_SEM_P(start_st, P_CHARACTER, word_st, characterAccumulateCmd);
            ADD_TRANSITION_SEM_P(word_st, P_CHARACTER, word_st, characterAccumulateCmd);
            ADD_TRANSITION_SEM_P(word_st, P_DIGIT, word_st, characterAccumulateCmd);
            ADD_TRANSITION_SEM_P(word_st, P_WHITE, start_st, wordCtrlCmd);
            ADD_TRANSITION_SEM(word_st, ';', start_st, wordCtrlCmd);
            ADD_TRANSITION_SEM(word_st, '{', start_st, wordCtrlCmd);

            cout << "Lexer::createTransitionGraph() add L_OPEN_PARENTHESIS" << endl;
            // L_OPEN_PARENTHESIS lexem
            openParenthesisCtrlCmd.assotiateWithLexer(this);
            openParenthesisCtrlCmd.assotiateWithCommand(&nullCmd, L_OPEN_PARENTHESIS);
            ADD_TRANSITION_SEM(start_st, '{', start_st, openParenthesisCtrlCmd);

            cout << "Lexer::createTransitionGraph() add L_CLOSING_PARENTHESIS" << endl;
            // L_CLOSING_PARENTHESIS lexem
            closingParenthesisCtrlCmd.assotiateWithLexer(this);
            closingParenthesisCtrlCmd.assotiateWithCommand(&nullCmd, L_CLOSING_PARENTHESIS);
            ADD_TRANSITION_SEM(start_st, '}', start_st, closingParenthesisCtrlCmd);

            // L_TRANSITION lexem
            transitionCtrlCmd.assotiateWithLexer(this);
            transitionCtrlCmd.assotiateWithCommand(&nullCmd, L_TRANSITION);
            DEFINE_STATE(trans_st1, STATE_ORDINARY);
            ADD_TRANSITION(start_st, '=', trans_st1);
            ADD_TRANSITION_SEM(trans_st1, '>', start_st, transitionCtrlCmd);
            
            // L_SEMICOLON lexem
            semicolonCtrlCmd.assotiateWithLexer(this);
            semicolonCtrlCmd.assotiateWithCommand(&nullCmd, L_SEMICOLON);
            ADD_TRANSITION_SEM(start_st, ';', start_st, semicolonCtrlCmd); 

            // L_CHAR lexem
            charCtrlCmd.assotiateWithLexer(this);
            charCtrlCmd.assotiateWithCommand(&characterAccumulateCmd, L_CHAR);
            DEFINE_STATE(chr_st_0, STATE_ORDINARY);
            DEFINE_STATE(chr_st_1, STATE_ORDINARY);
            ADD_TRANSITION(start_st, '\'', chr_st_0);
            ADD_TRANSITION_SEM_P(chr_st_0, P_CHARACTER, chr_st_1, characterAccumulateCmd);
            ADD_TRANSITION_SEM_P(chr_st_0, P_DIGIT, chr_st_1, characterAccumulateCmd);
            ADD_TRANSITION_SEM(chr_st_1, '\'', start_st, charCtrlCmd); 
        }

        void initReservedWords() {
            reserved_words_["automaton"] = L_AUTOMATON;
            reserved_words_["state"] = L_STATE;
            reserved_words_["final"] = L_FINAL;
            reserved_words_["start"] = L_START;
            reserved_words_["start"] = L_START;
            reserved_words_["{"] = L_OPEN_PARENTHESIS;
            reserved_words_["}"] = L_CLOSING_PARENTHESIS;
            reserved_words_["=>"] = L_TRANSITION;
            reserved_words_[";"] = L_SEMICOLON;
        }

        LexemType parseLexemType(string& word) {
        #ifdef LEXER_DEBUG
            cout << "Lexer:::parseLexemType()" << endl;
        #endif
            if (reserved_words_.find(word) != reserved_words_.end()) {
                return reserved_words_[word];
            }
            return L_IDENTIFIER;
        }

        bool match(LexemType) {
            return false;
        } 
}; 

#endif
