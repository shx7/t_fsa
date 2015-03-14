#include "TransitionMatrix.h"

void TransitionMatrix::addTransition(
        char* start_state_name,
        char  input,
        char* end_state_name)
{
    string start_str(start_state_name);
    string end_str(end_state_name);
    addTransition(start_str, input, end_str);
} 

void TransitionMatrix::addTransition(
        string& start_state_name,
        char    input,
        string& end_state_name)
{
    addRow(start_state_name);
    addRow(end_state_name);

    createTransition(
            start_state_name,
            input,
            end_state_name); 
}

/*void addTransition(
        State& start_state,
        char    input,
        State& end_state) 
{
}*/

void TransitionMatrix::addRow(string& start_state_name) {
    if (!isRowExists(start_state_name)) {
        createRow(start_state_name);
    }
}

void TransitionMatrix::print() {
    map<string, TransitionRow*>::iterator itr;
    for (itr = transition_row_table_.begin(); itr != transition_row_table_.end(); itr++) {
        itr->second->print();
    }
} 

bool TransitionMatrix::isRowExists(string st_name) {
    map<string, TransitionRow*>::iterator itr;
    itr = transition_row_table_.find(st_name);

    if (itr == transition_row_table_.end()) {
        return false;
    }

    return true; 
} 

void TransitionMatrix::createRow(string state_name) {
    State state(state_count_, state_name);
    state_count_++;
    transition_row_table_[state_name] = new TransitionRow(state);
}

void TransitionMatrix::createTransition(
        string& start_state_name,
        char    input,
        string& end_state_name)
{
    State end_state = transition_row_table_[end_state_name]->getStartState();
    transition_row_table_[start_state_name]->addTransition(input, end_state);
}
