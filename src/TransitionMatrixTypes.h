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

#define NULL_CHARACTER 0

using namespace std;

typedef unsigned long StateID;

enum StateType {
    STATE_START,
    STATE_FINAL,
    STATE_ORDINARY
};

struct State {
    public:
        StateID   id_;
        string    name_;
        StateType type_;

        State(string name, StateType type = STATE_ORDINARY, StateID id = -1) : id_(id), name_(name), type_(type) {};

        void print() {
            cout << "State: \"" << name_ << "\", id: " << id_ << endl;
            cout << "state type: ";
            printStateType();
            cout << endl;
        }

    private:
        void printStateType() {
            switch (type_) {
                case STATE_START:
                    cout << "Start"; 
                    break;

                case STATE_FINAL:
                    cout << "Finish";
                    break;

                case STATE_ORDINARY:
                    cout << "Oridnary";
                    break;
            }
        }
};

typedef vector<char>       InputSequence;
typedef vector<State>      StateSequence; 

#endif
