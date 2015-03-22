#include <stdio.h>
#include <iostream>
#include "TransitionGraph.h"
#define DEBUG

using namespace std;

int main(int argc, char** argv) {
    TransitionGraph graph;
    State state1("first_state", STATE_START);
    State state2("second state", STATE_ORDINARY);
    State state3("third statte", STATE_FINAL);
    graph.addTransition(state1, 'a', state2);
    graph.addTransition(state1, 'b', state2);
    graph.addTransition(state2, 'a', state1);
    graph.addTransition(state1, NULL_CHARACTER, state3);
    graph.addTransition(state1, 'c', state3);
    graph.addTransition(state1, 'd', state3);
    #ifdef DEBUG
    graph.print();
    #endif
    cout << "NEXT state" << endl;
    string st1("first_state");
    string st2("second state");
    graph.getNextState(st2, 'a')->print();
    return 0;
}
