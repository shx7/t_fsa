#include <stdio.h>
#include <iostream>
#include "TransitionGraph.h"
#include "Engine.h"

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
    Engine engine;
    InputSequence input;
    input.push_back('a');
    input.push_back('a');
    input.push_back('a');
    input.push_back('a');
    input.push_back('b');
    input.push_back('a');
    input.push_back('d');
    EngineReport *report = engine.run(graph, input);
    report->print();
    return 0;
}
