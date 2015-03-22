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

using namespace std; 

class StateNode {
    private:
        class Transition {
            public:
                char       input_;
                StateNode* node_;

                Transition() : node_(NULL), input_(NULL_CHARACTER) {}

                void print() {
                    /*cout << "Link by character: \'" << 
                        (input_ == NULL_CHARACTER) ? "NULL_CHARACTER" : input_ << "\'" << endl;
                    cout << "To: " << (node_ == NULL) ? "NULL_NODE" : node_->getNodeName() << endl;*/
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
