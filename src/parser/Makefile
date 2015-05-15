CC=g++
INCLUDE_DIR=../headers
CFLAGS=-I $(INCLUDE_DIR) -c -std=c++11

all: parser
parser: 
	$(CC) Parser.cpp $(CFLAGS)

lexer_sem:
	$(CC) $(SEMANTIC_CMDS) $(CFLAGS)

clean:
	rm *.o
