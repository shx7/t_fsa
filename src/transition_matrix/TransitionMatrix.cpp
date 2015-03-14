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

TransitionRow* TransitionMatrix::getStartStateRow() {
    map<string, TransitionRow*>::iterator itr;
    State* result;
    for (itr = transition_row_table_.begin(); itr != transition_row_table_.end(); itr++) {
        if (itr->second->isStartingStateRow()) {
            return itr->second;
        }
    }
    return NULL;
}

bool TransitionMatrix::isRowExists(State& state) {
    map<string, TransitionRow*>::iterator itr;
    itr = transition_row_table_.find(state.name_);

    if (itr == transition_row_table_.end()) {
        return false;
    }

    return true; 
} 
