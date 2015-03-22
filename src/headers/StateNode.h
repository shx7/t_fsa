/**********************************************************
*
*   PURPOSE: StateNode contains information about State
*            and transition(link) to other state by
*            concrete input
*
**********************************************************/
#ifndef STATE_NODE_H
#define STATE_NODE_H

#include "State.h"
#include <vector>
#include <iostream>

using namespace std; 

class StateNode {
    private:
        class Transition {
            public:
                char       input_;
                StateNode* node_;

                Transition() : node_(NULL), input_(NULL_CHARACTER) {}

                void print() {
                    cout << "Link by character: \'";
                    if (input_ == NULL_CHARACTER) {
                        cout << "NULL_CHARACTER";
                    } else {
                        cout << input_;
                    } 
                    cout << "\'" << endl;
                    cout << "To: ";
                    if (node_ == NULL) {
                        cout << "NULL_NODE";
                    } else {
                        cout << node_->getNodeName();
                    }
                    cout << endl;
                }
        };

        /*bool isInputExists(char input) {
            vector<Transition>::iterator itr;
            for (itr = transition_list_.begin(); itr != transition_list_.end(); itr++) {
                if (*itr == input) {
                    return true;
                }
            }
            return false; 
        }*/

    public:
        StateNode() {} 

        StateNode(State& state) {
            setState(state);
        }

        void setState(State& state);

        void addTransition(char input, StateNode* node);

        StateNode* getNextNode(char input);

        StateType getNodeType(); 

        string getNodeName();

        void print();

    private: 
        State              state_;
        vector<Transition> transition_list_;
};
#endif
