#include <stdio.h>
#include <iostream>
#include "Lexer.h"
#include "TransitionMatrix.h"

using namespace std;

int main(int argc, char** argv) {
    Token token_;
    Lexer lexer(cin);
    token_ = lexer.getNextToken();
    return 0;
}
