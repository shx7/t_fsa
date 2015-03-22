/***********************************************************
*
*   PURPOSE: Transition matrix is data structure, that
*            represents the way how automaton should
*            react(change his states) relativetely to 
*            input effects(input characters)
*            Every row contains information about state,
*            input character(sequence of chars, if automaton
*            is nondeterministic[1]) and transition to related
*            states(sequence in case [1])
*
***********************************************************/
#ifndef TRANSITION_MATRIX_H
#define TRANSITION_MATRIX_H

#include <vector>
#include <list>
#include <iostream>
#include <map>

#include "TransitionRow.h"

using namespace std;

class TransitionMatrix {
    private:
        map<string, TransitionRow*> transition_row_table_; // string and states relation
        long                        state_count_;
        State*                      illegal_state_;

    public:
        TransitionMatrix() : state_count_(0) {
            createIllegalState();
        }

        void addTransition(
                State& start_state,
                char    input,
                State& end_state);

        void print();

        State getStartState();

        State getNextState(State& state, char input);

    private:
        void addRow(State& state);

        bool isRowExists(State& state);

        void createIllegalState();

        State getIllegalState();
};

#endif
