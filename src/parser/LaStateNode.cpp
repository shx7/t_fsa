#include "LaStateNode.h"

void LaStateNode::addTransition(string &input, LaStateNode* node) {
    addTransition(input, node, null_semantic_cmd_);
}

void LaStateNode::addTransition(string &input,
        LaStateNode* node,
        SemanticCommand& cmd) {
   /*Transition transition(node, input, cmd);
    transition_list_.push_back(transition); */
}

LaStateNode* LaStateNode::getNextNode(string &input) {
    /*vector<Transition>::iterator itr;
    for (itr = transition_list_.begin(); itr != transition_list_.end(); itr++) {
        if ((*itr).input_ == input) {
            (*itr).callSemantic(input);
            return (*itr).node_;
        }
    }*/
    return NULL;
} 
