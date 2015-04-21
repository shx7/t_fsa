#include "Engine.h"

EngineReport Engine::run(TransitionGraph& graph, InputSequence& input) {
    cout << "ENGINE:: run()" << endl;
    initRun(graph, input);
    while (current_character_ != NULL_CHARACTER) {
        cout << "ENGINE: current character \"" << current_character_ << "\"" << endl;
        step();
        current_character_ = getNextCharacter();
    }

    // Process NULL_CHARACTER
    cout << "ENGINE: current character \"" << current_character_ << "\"" << endl;
    step();

    return formReport();
}

void Engine::step() {
    State* tmp = current_state_;
    current_state_ = graph_.getNextState(current_state_->name_, current_character_);
    delete tmp; // Deallocation last state*/
}

void Engine::initRun(TransitionGraph& graph, InputSequence& input) {
    graph_ = graph;
    input_ = input;
    current_input_ = input_.begin();
    current_state_ = graph_.getStartState();
    current_character_ = getNextCharacter();
}

void Engine::printCurrentState() {
    if (current_state_ != NULL) {
        current_state_->print();
    } else {
        cerr << "Engine::printCurrentState() NULL current_state_" << endl;
    }
}

EngineReport Engine::formReport() {
    EngineReport report;
    report.finish_state = current_state_; 
    if (current_state_->type_ == STATE_FINAL) {
        report.is_sequence_recognized = true;
    } else {
        report.is_sequence_recognized = false;
    }
    return report;
}

unsigned char Engine::getNextCharacter() {
    unsigned char result;
    if (current_input_ == input_.end()) {
        return NULL_CHARACTER;
    }
    result = *current_input_;
    current_input_++;
    return result;
}
