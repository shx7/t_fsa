CC=g++

all: main

main: lexer transition_matrix
	$(CC) main.cpp Lexer.o Transition.o TransitionRow.o TransitionMatrix.o -o t_fsa.elf

lexer:
	$(CC) Lexer.cpp -c

transition_matrix: transition transition_row
	$(CC) TransitionMatrix.cpp -c

transition:
	$(CC) Transition.cpp -c

transition_row:
	$(CC) TransitionRow.cpp -c

clean:
	rm *.o
	rm *.elf
