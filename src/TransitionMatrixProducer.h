/***********************************************************
*
*   PURPOSE: Produce an transition matrix for
*            [non]deterministic finite automaton, this
*            matrix will be used in AutomatonMachine
*
***********************************************************/
#ifndef TRANSITION_MATRIX_PRODUCER_H
#define TRANSITION_MATRIX_PRODUCER_H
class TransitionMatrixProducer {
    private:

    public:
        void addTransition(State& start_state,
                char input, 
                State& end_state) {

        }

        TransitionMatrix* produceMatrix() {
            return new TransitionMatrix();
        }
}
#endif
