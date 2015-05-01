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

//#define LEXER_DEBUG

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
            initReservedWords();
            createTransitionGraph();
        }

        void runParse(); 
    private: 

        void pushToken(Token& token);

        void printTokenContainer();

        unsigned char getNextChar();

        void createTransitionGraph();

        void initReservedWords();

        LexemType parseLexemType(string& word);

        bool match(LexemType);
}; 

#endif
