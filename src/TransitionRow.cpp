#include "TransitionRow.h"

void TransitionRow::print() {
    TransitionSequence::iterator itr;
    cout << "Row represents state: ";
    start_state_.print();
    cout << " consists of: " << endl;
    for (itr = transition_seq_.begin(); itr != transition_seq_.end(); itr++) 
    {
        (*itr).print();
    }
} 

void TransitionRow::addTransition(Transition& transition) {
    transition_seq_.push_back(transition);
}
