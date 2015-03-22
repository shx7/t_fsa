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

class TransitionGraph {
    public:
        void addTransition(State& start_state,
               char input,
               State& end_state);

        void addState(string& name, StateType type); 
        void addState(State& state);

        // Allocates new State
        State* getNextState(string& name, char input);

        void print();

    private:
        bool isStateNodeExists(string& name);
        StateNode* findStateNode(string& name);

    private:
        map<string, StateNode> state_node_table_;
};

#endif
