/**********************************************************
*
*   PURPOSE: Declare inner data types for 
*   TransitionMatrix
*
**********************************************************/
#ifndef TRANSITION_MATRIX_TYPES_H
#define TRANSITION_MATRIX_TYPES_H

typedef unsigned long StateID;

struct State {
    StateID id_;
    string name_;
};

typedef vector<char> InputSequence;
typedef vector<State> StateSequence;

#endif
