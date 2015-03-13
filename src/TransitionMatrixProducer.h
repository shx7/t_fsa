/***********************************************************
*
*   PURPOSE: Produce an transition matrix for
*            [non]deterministic finite automaton, this
*            matrix will be used in AutomatonMachine
*
***********************************************************/
#ifndef STATE_TRANSITION_MATRIX_PRODUCER_H
#define STATE_TRANSITION_MATRIX_PRODUCER_H
class StateTransitionMatrixProducer {
    private:

    public:
        StateMatrixProducer() {
        }

        void addTransition(State& state,
                InputSequence& input, 
                StateSequence& transition_states) {
        }

        TransitionMatrix* produceMatrix() {
        }
}
#endif
