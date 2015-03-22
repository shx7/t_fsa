#include "Engine.h"
/*
EngineReport* Engine::run(TransitionMatrix& matrix, InputSequence& input) {
    initRun(matrix, input);
    char next_char = getNextInput(); 
    for (; next_char != NULL_CHARACTER; next_char = getNextInput()) {
        step(next_char);
    } 
    return formReport(); 
}

void Engine::step(char input) {
    current_state_row_ = getNextStateRow(input);
    if (current_state_row_ == NULL) {
        cerr << "Engine::step() automaton is not full. Exitti'n" << endl;
        return;
    }
    printCurrentState();
}

void Engine::initRun(TransitionMatrix& matrix, InputSequence& input) {
    start_state_row_ = matrix.getStartStateRow(); 
    current_state_row_ = start_state_row_;
    input_ = input;
    current_input_ = input_.begin();
}

void Engine::printCurrentState() {
    cout << "Current state is: " << endl;
    current_state_row_->getStartState().print();
    cout << "Current input is: " << *current_input_ << endl;
    cout << "----------------------------" << endl;
}

TransitionRow* Engine::getNextStateRow(char input) {
    // Look for transition
    return NULL;
}

char Engine::getNextInput() {
    char result;
    if (current_input_ == input_.end()) {
        return NULL_CHARACTER;
    }
    result = *current_input_;
    current_input_++;
    return result;
}

EngineReport* Engine::formReport() {
    EngineReport* report = new EngineReport();
    report->finish_state = current_state_row_->getStartState(); 
    if (report->finish_state.type_ == STATE_FINAL) {
        report->is_sequence_recognized = true;
    } else {
        report->is_sequence_recognized = false;
    }
    return report;
}
*/
