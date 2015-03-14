#include "Engine.h"

EngineReport* Engine::run(TransitionMatrix& matrix, InputSequence& input) {
    initRun(matrix, input);
    return NULL;
}


void Engine::step() {
}

void Engine::initRun(TransitionMatrix& matrix, InputSequence& input) {
    start_state_ = matrix.getStartStateRow(); 
    current_input_ = input.begin();
}

void Engine::printProgress() {
}
