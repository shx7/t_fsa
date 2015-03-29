#include <stdio.h>
#include <iostream>
#include "TransitionGraph.h"
#include "Engine.h"

using namespace std;

void test_1();
void test_2();
void test_3();

int main(int argc, char** argv) {
    test_3();
    return 0;
}

void test_1() {
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
    input.push_back('f');
    EngineReport report = engine.run(graph, input);
    report.print(); 
}

void test_2() {
    TransitionGraph graph;
    State state1("first_state", STATE_START);
    State state2("second state", STATE_ORDINARY);
    State state3("third statte", STATE_ORDINARY);
    State state4("fourth statte", STATE_FINAL);
    graph.addTransitionByPredicat(state1, state2, P_CHARACTER);
    graph.addTransitionByPredicat(state2, state3, P_CHARACTER);
    graph.addTransitionByPredicat(state3, state4, P_DIGIT);
    Engine engine;
    InputSequence input;
    input.push_back('a');
    input.push_back('S');
    input.push_back('9');
    input.push_back(0);
    EngineReport report = engine.run(graph, input);
    report.print();
}

void test_3() {
    TransitionGraph graph;
    State state1("first_state", STATE_START);
    State state2("second", STATE_FINAL);
    graph.addTransitionByPredicat(state1, state2, P_CHARACTER);
    graph.addTransitionByPredicat(state2, state2, P_ANY);
    Engine engine;
    InputSequence input;
    input.push_back('a');
    input.push_back('S');
    input.push_back(0);
    EngineReport report = engine.run(graph, input);
    report.print();
}
