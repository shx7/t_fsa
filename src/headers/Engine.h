/**********************************************************
*
*   PURPOSE: Engine runs automaton, represented by 
*            TransitionMatrix with input InputSequence, but
*            only if automaton is deterministic.
*            After run Engine returns EngineReport, consists
*            of State on which it stop execution, 
*            recognition result
*
**********************************************************/
#ifndef ENGINE_H
#define ENGINE_H

#include "TransitionMatrix.h"
#include "TransitionMatrixTypes.h"

struct EngineReport {
    State finish_state;
    bool  is_sequence_recognized;

    EngineReport() : is_sequence_recognized(false) {};
};

class Engine {
    private:
        TransitionRow*          start_state_row_;
        TransitionRow*          current_state_row_;
        InputSequence::iterator current_input_;
        InputSequence           input_;

    public:
        EngineReport* run(TransitionMatrix& matrix, InputSequence& input);

        void printReport(EngineReport* report); 

    private:
        void step(char input);

        void initRun(TransitionMatrix& matrix, InputSequence& input);

        void printCurrentState();

        TransitionRow* getNextStateRow(char input);

        char getNextInput();

        EngineReport* formReport();
};
#endif
