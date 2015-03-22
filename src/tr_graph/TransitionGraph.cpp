#include "TransitionGraph.h"

bool TransitionGraph::isStateNodeExists(string& name) {
    map<string, StateNode>::iterator itr;
    itr = state_node_table_.find(name);
    if (itr == state_node_table_.end()) {
        return false;
    }
    return true;
}

StateNode* TransitionGraph::findStateNode(string& name) {
    map<string, StateNode>::iterator itr;
    itr = state_node_table_.find(name);
    if (itr == state_node_table_.end()) {
        return NULL;
    }
    return &(itr->second);
}

void TransitionGraph::addTransition(State& start_state,
       char input,
       State& end_state)
{
    StateNode *start_node, *end_node;
    addState(start_state);
    addState(end_state);
    start_node = findStateNode(start_state.name_);
    end_node = findStateNode(end_state.name_);
    start_node->addTransition(input, end_node);
}

void TransitionGraph::addState(string& name, StateType type) {
    if (isStateNodeExists(name)) {
        return;
    }
    State state;
    state.name_ = name;
    state.type_ = type;
    addState(state);
}

void TransitionGraph::addState(State& state) {
    if (isStateNodeExists(state.name_)) {
        return;
    }
    StateNode state_node;
    state_node.setState(state);
    state_node_table_[state.name_] = state_node;
}

// FIX HERE
State* TransitionGraph::getNextState(string& name, char input) {
    return new State(name);
}

void TransitionGraph::print() {
    map<string, StateNode>::iterator itr;
    for (itr = state_node_table_.begin(); itr != state_node_table_.end(); itr++) {
        itr->second.print();
        cout << "------------------------" << endl;
    }
} 
