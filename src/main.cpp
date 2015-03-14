#include <stdio.h>
#include <iostream>
#include "Lexer.h"
#include "TransitionMatrix.h"

using namespace std;

int main(int argc, char** argv) {
    TransitionMatrix matrix;
    string start_state("solitude");
    string end_state("sommerfield");
    matrix.addTransition(start_state, 'a', end_state);
    matrix.print();
    return 0;
}
