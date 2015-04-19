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
#include "SemanticCommand.h"
#include "NullSemanticCommand.h"
#include <vector>
#include <iostream>

using namespace std; 

typedef void TransitionEntry(void);

class StateNode {
    private:
        class Transition {
            public:
                unsigned char   input_;
                StateNode       *node_; // End point of transition
                SemanticCommand *cmd_;

                Transition() : node_(NULL), input_(NULL_CHARACTER), cmd_(NULL) {}

                Transition(StateNode* node,
                        unsigned char input,
                        SemanticCommand& cmd) : node_(node), input_(input), cmd_(&cmd) {}

                void callSemantic(unsigned char input) {
                #ifdef TRANSITION_DEBUG
                    cout << "Transition::callSemantic(\'" << input << "\')" << endl;
                #endif
                    if (cmd_ != NULL) {
                        cmd_->command(input);
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
                    //cout << " semantic addr: " << semanticFunction_ << endl;
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
                SemanticCommand& cmd);

        StateNode* getNextNode(char input);

        StateType getNodeType(); 

        string getNodeName();

        void print();

    private: 
        State               state_;
        vector<Transition>  transition_list_;
        NullSemanticCommand null_semantic_cmd_;
};
#endif
