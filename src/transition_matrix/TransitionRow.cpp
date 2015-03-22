#include "TransitionRow.h"

void TransitionRow::print() {
    TransitionSequence::iterator itr;
    cout << endl << ">ROW represents STATE: " << endl;
    state_.print();
    cout << "CONSISTS of: " << endl;
    for (itr = transition_seq_.begin(); itr != transition_seq_.end(); itr++) 
    {
        (*itr).print();
    }
    cout << "--------------END Row print-------------" << endl;
} 
        
void TransitionRow::addTransition(char input, State& end_state) {
    Transition transition(state_, end_state);

    if (!isTransitionExists(transition)) {
        transition_seq_.push_back(transition);
    } 

    // Add chars to find transition
    Transition* mod_transition = findTransition(transition.getEndState()->name_); 
    if (mod_transition == NULL) {
        cerr << "TransitionRow::addTransition(Transition& transition)" << endl;
        //exit();
    }
    mod_transition->addInputChar(input); 
}

void TransitionRow::addTransition(Transition& transition) {
}

// IMPORTANT: do not forget to fix getters for Transition
bool TransitionRow::isTransitionExists(Transition& transition) {
    return isTransitionExists(transition.getStartState()->name_, transition.getEndState()->name_);
}

bool TransitionRow::isTransitionExists(
        string& start_state_name,
        char input) 
{
    TransitionSequence::iterator itr;
    for (itr = transition_seq_.begin(); itr != transition_seq_.end(); itr++) {
        if ((*itr).getStartState()->name_ == start_state_name) {
            return (*itr).isInputExists(input);
        } 
    }
    return false; 
} 

// FIX Transiiton::getEndState
State TransitionRow::getTransitionState(State& state, char input) {
    TransitionSequence::iterator itr;
    for (itr = transition_seq_.begin(); itr != transition_seq_.end(); itr++) {
        if ((*itr).isInputExists(input)) {
            return *((*itr).getEndState());
        } 
    } 
}

bool TransitionRow::isTransitionExists(
        string& start_state_name,
        string& end_state_name) 
{
    TransitionSequence::iterator itr;
    for (itr = transition_seq_.begin(); itr != transition_seq_.end(); itr++) {
        if (((*itr).getStartState()->name_ == start_state_name) &&
            ((*itr).getStartState()->name_ == end_state_name)) {
            return true;
        }
    }
    
    return false; 
}

Transition* TransitionRow::findTransition(string& end_state_name) {
    TransitionSequence::iterator itr;
    for (itr = transition_seq_.begin(); itr != transition_seq_.end(); itr++) {
           if ((*itr).getEndState()->name_ == end_state_name) return &(*itr);
    }
    return NULL;
}



State TransitionRow::getState() {
    return state_;
}

bool TransitionRow::isStartingStateRow() {
    if (state_.type_ == STATE_START) {
        return true;
    }
    return false;
}

