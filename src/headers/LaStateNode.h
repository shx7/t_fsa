/**********************************************************
*
*   PURPOSE: LaStateNode contains information about State
*            and transition(link) to other state by
*            concrete input. But this StateNode can decide 
*            which transition to choose by examining
*            context in which executes, passed by string.
*
**********************************************************/
#ifndef LA_STATE_NODE_H
#define LA_STATE_NODE_H

#include "State.h"
#include "SemanticCommand.h"
#include "NullSemanticCommand.h"
#include <vector>
#include <iostream>
#include "StateNode.h"

using namespace std; 

class LaStateNode : protected StateNode {
    protected: 

        /***********************************************************
        *
        *   PURPOSE: This class differs from StateNode::Transition,
        *            because in LaStateNode we should analyze context
        *
        ***********************************************************/
        class Transition {
            public:
                string          input_;
                LaStateNode     *node_; // End point of transition
                SemanticCommand *cmd_;

                Transition() : node_(NULL), input_(NULL_CHARACTER), cmd_(NULL) {}

                Transition(LaStateNode* node,
                        string& input,
                        SemanticCommand& cmd) : node_(node), input_(input), cmd_(&cmd) {}

                void callSemantic(string &input) {
                #ifdef TRANSITION_DEBUG
                    cout << "Transition::callSemantic(\'" << input << "\')" << endl;
                #endif
                    if (cmd_ != NULL) {
                        cmd_->command(input[0]);
                    } 
                }

                void print() {
                    cout << "Link by character: \'";
                    if (input_ == string(NULL_CHARACTER)) {
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
        void addTransition(string &input, LaStateNode* node);

        void addTransition(string &input,
            LaStateNode* node,
            SemanticCommand& cmd);

        LaStateNode* getNextNode(string &input);
};
#endif
