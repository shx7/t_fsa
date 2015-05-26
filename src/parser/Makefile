CC=g++
INCLUDE_DIR=../headers
CFLAGS=-I $(INCLUDE_DIR) -c -std=c++11

all: parser state_node
parser: 
	$(CC) Parser.cpp $(CFLAGS)

state_node:
	$(CC) LaStateNode.cpp $(CFLAGS)

clean:
	rm *.o
