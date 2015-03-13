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

using namespace std;

namespace transition {

    typedef unsigned long StateID;

    struct State {
        StateID id_; // Also number of row in matrix
        string name_;

        State(StateID id, string name) : id_(id), name_(name) {};
    };

    typedef vector<char> InputSequence;
    typedef vector<State> StateSequence;

    class Row {
        State state_;
        InputSequence input_seq;
        StateSequence state_transition_seq;

        // DEBUG feature
        void print() {
        }
    }; 

    class Matrix {
        private:
            list<Row>             matrix_;
            map<string, State*>   state_map_; // for detecting row to modify
            long                  state_count_;

        public:
            void addTransition(
                    string& start_state_name,
                    char input_,
                    string& end_state_name)
            {
                if (isStateExists(start_state_name)) {
                    createRow(start_state_name);
                } 

                if (isStateExists(end_state_name)) {
                    createRow(start_state_name);
                } 
            }

            // *DEBUG*
            void print() {
            }

        private:
            bool isStateExists(string& st_name) {
                return false;
            }

            void createRow(string& state_name) {
                state_map_[state_name] = new State(state_count_, state_name);
                state_count_++;
            }

            void addTransitionToRow(
                    StateID start_state_id,
                    char input_,
                    StateID end_state_id) 
            {
            }
    };
}

#endif
