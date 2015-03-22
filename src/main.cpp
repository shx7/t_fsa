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
    State state4("fourth statte", STATE_FINAL);
    graph.addTransition(state1, 'a', state2);
    graph.addTransition(state1, 'b', state2);
    graph.addTransition(state1, 'f', state2);
    graph.addTransition(state2, 'c', state3);
    graph.addTransition(state3, NULL_CHARACTER, state3);
    graph.addTransition(state3, 'g', state4);
    #ifdef DEBUG
    graph.print();
    #endif
    return 0;
}
