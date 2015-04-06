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


void TransitionGraph::addTransitionByPredicat(State& start_state,
       State& end_state,
       Predicat predicat)
{
    switch(predicat) {
        case P_CHARACTER:
            for (unsigned char i = 'A'; i <= 'Z'; i++) {
                addTransition(start_state, i, end_state);
            }

            for (unsigned char i = 'a'; i <= 'z'; i++) {
                addTransition(start_state, i, end_state);
            }
            break;

        case P_DIGIT:
            for (unsigned char i = '0'; i <= '9'; i++) {
                addTransition(start_state, i, end_state);
            }
            break;

        case P_ANY:
            for (unsigned char i = 0; i <= 254; i++) {
                addTransition(start_state, i, end_state);
            }
            break; 

        case P_WHITE:
            addTransition(start_state, ' ', end_state);
            addTransition(start_state, '\n', end_state);
            addTransition(start_state, '\t', end_state);

        default:
            cerr << "TransitionGraph::addTransitionByPredicat() unknown predicat" << endl;
    }
}

void TransitionGraph::addTransition(State& start_state,
       unsigned char input,
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

// Return new state
State* TransitionGraph::getNextState(string& name, char input) {
    StateNode *node = findStateNode(name);
    StateNode *next_node;
    if (node != NULL) {
        next_node = node->getNextNode(input);
        if (next_node != NULL) {
            return new State(next_node->getNodeName(), next_node->getNodeType()); 
        }
    }
    return illegal_state_;
}

void TransitionGraph::print() {
    map<string, StateNode>::iterator itr;
    for (itr = state_node_table_.begin(); itr != state_node_table_.end(); itr++) {
        itr->second.print();
        cout << "------------------------" << endl;
    }
} 

State* TransitionGraph::getStartState() {
    map<string, StateNode>::iterator itr;
    for (itr = state_node_table_.begin(); itr != state_node_table_.end(); itr++) {
        if (itr->second.getNodeType() == STATE_START) {
            return new State(itr->second.getNodeName(), itr->second.getNodeType());
        }
    }
   return illegal_state_;
}

void TransitionGraph::initIllegalState() {
    illegal_state_ = new State("STATE_ILLEGAL", STATE_ORDINARY);
    addTransitionByPredicat(*illegal_state_, *illegal_state_, P_ANY);
}
