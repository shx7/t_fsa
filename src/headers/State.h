/**********************************************************
*
*   PURPOSE: State describe concrete state without links
*            to other
*
**********************************************************/
#ifndef STATE_H
#define STATE_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define NULL_CHARACTER 0 

typedef unsigned long StateID;

enum StateType {
    STATE_START,
    STATE_FINAL,
    STATE_ORDINARY,
    STATE_START_FINAL
};

struct State {
    public:
        StateID   id_;
        string    name_;
        StateType type_;

        State(string name = "", StateType type = STATE_ORDINARY, StateID id = -1) : name_(name), type_(type), id_(id) {};

        State(const State& state) : name_(state.name_), type_(state.type_), id_(0) {};

        bool operator==(State& state) {
            if (name_ == state.name_) {
                return true;
            }
            return false;
        }

        void print() {
            cout << "State: \"" << name_ << "\" state type: ";
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

                case STATE_START_FINAL:
                    cout << "State & Final";
            }
        }
};

#endif
