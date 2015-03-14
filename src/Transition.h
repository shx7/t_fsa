/**********************************************************
*
*   PURPOSE: Transition shows from which start_state_
*            by which input characters we go to end_state_.
*            Used by TransitionMatrix and TransitionRow
*
**********************************************************/
#ifndef TRANSITION_H
#define TRANSITION_H
#include "TransitionMatrixTypes.h"
#include <string>
#include <iostream>

using namespace std;

class Transition {
    private:
        State         start_state_;
        State         end_state_;
        InputSequence input_seq_;

    public:
        Transition(State& start_state, State& end_state) : 
                start_state_(start_state),
                end_state_(end_state) {}

        // DEBUG feature
        void print();

        void addInputChar(char input);

        State* getStartState() {
            return &start_state_;
        }

        State* getEndState() {
            return &end_state_;
        }

    private:
        void printInputSequence();
        
        void printStartState();

        void printEndState();

        /*void printStateSequence() {
            StateSequence::iterator itr;
            cout << "State sequence: " << endl;
            for (itr = state_transition_seq_.begin(); itr != state_transition_seq_.end(); itr++) {
                (*itr).print();
            } 
        }*/
}; 

#endif
