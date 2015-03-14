#include <stdio.h>
#include <iostream>
#include "Lexer.h"
#include "TransitionMatrix.h"

using namespace std;

int main(int argc, char** argv) {
    TransitionMatrix matrix;
    string state1("state1");
    string state2("state2");
    string state3("state3");
    matrix.addTransition(state1, 'a', state2);
    matrix.addTransition(state3, 'c', state2);
    matrix.print();
    return 0;
}
