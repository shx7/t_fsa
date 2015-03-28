/**********************************************************
*
*   PURPOSE: Engine runs automaton, represented by 
*            TransitionMatrix with input InputSequence, but
*            only if automaton is deterministic.
*            After run Engine returns EngineReport, consists
*            of State on which it stop execution, 
*            recognition result
*
**********************************************************/
#ifndef ENGINE_H
#define ENGINE_H

#include "TransitionGraph.h"
#include <vector>
#include <iostream>

using namespace std;
typedef vector<char> InputSequence;

struct EngineReport {
    State *finish_state;
    bool  is_sequence_recognized;

    EngineReport() : is_sequence_recognized(false) {};

    void print() {
        cout << "Sequence " << (is_sequence_recognized ? "has" : "has not") << " been recognized" << endl;
        cout << "Recognition stops on state:" << endl;
        finish_state->print();
    }
};

class Engine {
    private:
        TransitionGraph         graph_;
        State                   *current_state_;
        InputSequence::iterator current_input_;
        InputSequence           input_;
        char                    current_character_;

    public:
        EngineReport run(TransitionGraph& graph, InputSequence& input);

    private:
        void step();

        void initRun(TransitionGraph& graph, InputSequence& input);

        EngineReport formReport();

        char getNextCharacter();

        void printCurrentState(); 
};
#endif
