CC=g++
CFLAGS=-I ../headers/

all: transition_graph

transition_graph: state_node
	$(CC) $(CFLAGS) TransitionGraph.cpp -c

state_node:
	$(CC) $(CFLAGS) StateNode.cpp -c

clean:
	rm *.o
