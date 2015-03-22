#include "TransitionMatrix.h"

void TransitionMatrix::addTransition(
        State& start_state,
        char    input,
        State& end_state) 
{
    addRow(start_state);
    addRow(end_state); 
    transition_row_table_[start_state.name_]->addTransition(input, end_state);
}

bool TransitionMatrix::isRowExists(State& state) {
    map<string, TransitionRow*>::iterator itr;
    itr = transition_row_table_.find(state.name_);

    if (itr == transition_row_table_.end()) {
        return false;
    }

    return true; 
}

void TransitionMatrix::addRow(State& state) {
    if (!isRowExists(state)) {
        state.id_ = state_count_;
        state_count_++;
        transition_row_table_[state.name_] = new TransitionRow(state); 
    }
}

void TransitionMatrix::print() {
    map<string, TransitionRow*>::iterator itr;
    for (itr = transition_row_table_.begin(); itr != transition_row_table_.end(); itr++) {
        itr->second->print();
    }
}

State TransitionMatrix::getStartState() {
    map<string, TransitionRow*>::iterator itr;
    for (itr = transition_row_table_.begin(); itr != transition_row_table_.end(); itr++) {
        if (itr->second->isStartingStateRow()) {
            return itr->second->getState();
        }
    }
    return getIllegalState();
} 

State TransitionMatrix::getNextState(State& current_state, char input) {
    map<string, TransitionRow*>::iterator itr;
    itr = transition_row_table_.find(current_state.name_);
    if (itr == transition_row_table_.end()) {
        return getIllegalState();
    }

    if ((itr->second)->isTransitionExists(current_state.name_, input)) {
        return (itr->second)->getTransitionState(current_state, input);
    }
    return getIllegalState();
}

void TransitionMatrix::createIllegalState() {
    illegal_state_ = new State("illegal_state", STATE_ORDINARY);
}

State TransitionMatrix::getIllegalState() {
    return *illegal_state_;
}
