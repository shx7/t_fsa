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

typedef void TransitionEntry(void);

class StateNode {
    private:
        class Transition {
            public:
                unsigned char input_;
                StateNode*    node_;
                void          (*semanticFunction_)(unsigned char);

                Transition() : node_(NULL), input_(NULL_CHARACTER), semanticFunction_(NULL) {}

                void callSemantic(unsigned char input) {
                    cout << "Transition::callSemantic(\'" << input << "\')" << endl;
                    if (semanticFunction_ != NULL) {
                        semanticFunction_(input);
                    } 
                }

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

    public:
        StateNode() {} 

        StateNode(State& state) {
            setState(state);
        }

        void setState(State& state);

        void addTransition(char input, StateNode* node);

        void addTransition(char input,
                StateNode* node,
                void (*semanticFunction)(unsigned char));

        StateNode* getNextNode(char input);

        StateType getNodeType(); 

        string getNodeName();

        void print();

    private: 
        State              state_;
        vector<Transition> transition_list_;
};
#endif
