# Finite state automaton with custom semantics
Main aim of this project - create virtual machine, that able to run FSA.
- FSA - finite state automaton, used for string interpretation.
- FSA consists of states, transition between states and commands, invoking when corresponding transition happens.
- Transition arise by concrete characted in input string.

Currently commands for FSA are hardcoded inside the program.

But i am planning to implement commands as Lua routines, linking dynamically to the interpreting engine.
