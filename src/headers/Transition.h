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
}; 

#endif
