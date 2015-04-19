#include "StateNode.h"

void StateNode::setState(State& state) {
    state_.name_ = state.name_;
    state_.type_ = state.type_;
}

void StateNode::addTransition(char input, StateNode* node) {
    addTransition(input, node, null_semantic_cmd_);
}

void StateNode::addTransition(char input,
        StateNode* node,
        SemanticCommand& cmd) {
    /*Transition transition;
    transition.input_ = input;
    transition.node_ = node;
    transition.cmd_ = &cmd;*/
    Transition transition(node, input, cmd);
    transition_list_.push_back(transition); 
}

StateNode* StateNode::getNextNode(char input) {
    vector<Transition>::iterator itr;
    for (itr = transition_list_.begin(); itr != transition_list_.end(); itr++) {
        if ((*itr).input_ == input) {
            (*itr).callSemantic(input);
            return (*itr).node_;
        }
    }
    return NULL;
}

StateType StateNode::getNodeType() {
    return state_.type_;
}

string StateNode::getNodeName() {
    return state_.name_;
}

void StateNode::print() {
    vector<Transition>::iterator itr;
    cout << "StateNode: " << endl;
    state_.print();
    cout << "Transitions:" << endl;
    for (itr = transition_list_.begin(); itr != transition_list_.end(); itr++) {
        (*itr).print();
    }
}

