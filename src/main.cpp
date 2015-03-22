#include <stdio.h>
#include <iostream>
#include "State.h"
#define DEBUG

using namespace std;

int main(int argc, char** argv) {
    /*TransitionMatrix matrix;
    State state1("first_state", STATE_START);
    State state2("second state", STATE_ORDINARY);
    State state3("third statte", STATE_FINAL);
    State state4("fourth statte", STATE_FINAL);
    matrix.addTransition(state1, 'a', state2);
    matrix.addTransition(state1, 'b', state2);
    matrix.addTransition(state1, 'f', state2);
    matrix.addTransition(state2, 'c', state3);
    matrix.addTransition(state3, NULL_CHARACTER, state3);
    matrix.addTransition(state3, 'g', state4);
    #ifdef DEBUG
    matrix.print();
    #endif*/
    State state1("asd", STATE_START);
    State state2("aasd", STATE_START);
    State state3("aasd", STATE_START);
    State state4("asd", STATE_ORDINARY);
    cout << (state1 == state4) << endl;
    return 0;
}
