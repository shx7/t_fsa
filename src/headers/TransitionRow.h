/**********************************************************
*
*   PURPOSE: TransitionRow represents all Transition's
*            leading from one(!) start_state_ to others
*            states, driven by input characters.
*            Consists of Transition's, every transition 
*            represents relation from start_state_ to
*            one end_state_
*            Used by TransitionMatrix
*
***********************************************************/
#ifndef TRANSITION_ROW_H
#define TRANSITION_ROW_H
#include "Transition.h"

typedef vector<Transition> TransitionSequence; 

class TransitionRow {
    private:
        vector<Transition> transition_seq_;
        State              state_; 

    public:
        TransitionRow(State& state) : state_(state) {}; 

        void addTransition(char input, State& end_state); 

        bool isTransitionExists(
                string& start_state_name,
                char input); 

        State getTransitionState(State& state, char input);

        State getState();

        void print();

        bool isStartingStateRow();

    private:

        void addTransition(Transition& transition);

        bool isTransitionExists(Transition& transition);

        bool isTransitionExists(
                string& start_state_name,
                string& end_state_name); 

       Transition* findTransition(string& end_state_name);
}; 

#endif 
