#include <stdio.h>
#include <iostream>
#include "TransitionGraph.h"
#include "Engine.h"
#include <vector>

using namespace std;

void test_1(void);
void test_2();
void test_3();

void print_1(unsigned char input) {
    cout << "PRINT! \'" << input << "\'" <<  endl;
}

int main(int argc, char** argv) {
    test_3();
    //void (*entry)(void);
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
    graph.addTransitionByPredicat(state1, P_CHARACTER, state2);
    graph.addTransitionByPredicat(state2, P_CHARACTER, state3);
    graph.addTransitionByPredicat(state3, P_DIGIT, state4);
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
    graph.addTransitionByPredicat(state1, P_CHARACTER, state2, print_1);
    graph.addTransitionByPredicat(state2, P_ANY, state2);
    //graph.print();
    Engine engine;
    InputSequence input;
    input.push_back('a');
    input.push_back('S');
    input.push_back('}');
    input.push_back(0);
    EngineReport report = engine.run(graph, input);
    report.print();
}
