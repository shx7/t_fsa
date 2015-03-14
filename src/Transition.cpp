#include "Transition.h"

void Transition::print() {
    cout << "Transition from: " << endl;
    printStartState();

    cout << "to: " << endl;
    printEndState();

    cout << "Driven by chars: " << endl;
    printInputSequence();
}

void Transition::addInputChar(char input) {
    input_seq_.push_back(input);
}

void Transition::printInputSequence() {
    InputSequence::iterator itr;
    for (itr = input_seq_.begin(); itr != input_seq_.end(); itr++) {
        cout << *itr << ", ";
    }
}

void Transition::printStartState() {
    start_state_.print();
}

void Transition::printEndState() {
    end_state_.print();
}


