CC=g++
CFLAGS=-I ../headers/

all: transition transition_row transition_matrix 

transition_matrix:
	$(CC) $(CFLAGS) TransitionMatrix.cpp -c

transition:
	$(CC) $(CFLAGS) Transition.cpp -c

transition_row:
	$(CC) $(CFLAGS) TransitionRow.cpp -c

clean:
	rm *.o
