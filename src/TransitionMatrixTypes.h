/**********************************************************
*
*   PURPOSE: Declare inner data types for 
*   TransitionMatrix
*
**********************************************************/
#ifndef TRANSITION_MATRIX_TYPES_H
#define TRANSITION_MATRIX_TYPES_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef unsigned long StateID;

struct State {
    StateID id_;
    string  name_;

    State(StateID id, string name) : id_(id), name_(name) {};

    void print() {
        cout << "State: \"" << name_ << "\", id: " << id_ << endl;
    }
};

typedef vector<char>       InputSequence;
typedef vector<State>      StateSequence; 

#endif
