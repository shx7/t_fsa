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
#include "Engine.h"

struct EngineReport {
    State* finished_state;
    bool   sequence_recognized;

    EngineReport() : sequence_recognized(false) {};
};

class Engine {
    private:
        TransitionRow*          start_state_;
        TransitionRow*          end_state_;
        InputSequence::iterator current_input_;

    public:
        EngineReport* run(TransitionMatrix& matrix, InputSequence& input);

        void printReport(EngineReport* report); 

    private:
        void step();

        void initRun(TransitionMatrix& matrix, InputSequence& input);

        void printProgress();
};
#endif
