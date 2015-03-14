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

    public:
        TransitionMatrix() : state_count_(0) {}

        // I think it will be unused
        void addTransition(
                char* start_state_name,
                char  input,
                char* end_state_name);
        
        void addTransition(
                string& start_state_name,
                char    input,
                string& end_state_name);

        void addRow(string& start_state_name);

        void print();

    private:
        bool isRowExists(string st_name);
       
        void createRow(string state_name);

        void createTransition(
                string& start_state_name,
                char    input,
                string& end_state_name);

        // Due to Map connects state string names
        // and related Row's transition created
        // between Row's, not states. It is not bug,
        // feature
        void createTransition (
                TransitionRow* start_row,
                char input,
                TransitionRow* end_row);
};

#endif
