/**********************************************************
*
*   PURPOSE: Contains all States and links between them
*            by input
*
**********************************************************/
#ifndef TRANSITION_GRAPH_H
#define TRANSITION_GRAPH_H

#include <map>
#include "State.h"
#include "StateNode.h"

using namespace std;

enum Predicat {
    P_CHARACTER,
    P_DIGIT,
    P_ANY
};

class TransitionGraph {
    public:
        TransitionGraph() {
            initIllegalState();
        }

        // Adding transition by predicat{characters, digits}
        void addTransitionByPredicat(State& start_state,
               State& end_state,
               Predicat predicat); 

        void addTransition(State& start_state,
               unsigned char input,
               State& end_state); 

        // Returns new allocated State. Memory should be freed
        State* getNextState(string& name, char input); 
        State* getStartState();

        void print();

    private:
        bool isStateNodeExists(string& name);
        StateNode* findStateNode(string& name);
        void initIllegalState();

        void addState(string& name, StateType type); 
        void addState(State& state);

    private:
        map<string, StateNode> state_node_table_;
        State*                 illegal_state_; // Special illegal state. Used, if input
                                               // automaton is not full to complete em to full automaton
};

#endif
