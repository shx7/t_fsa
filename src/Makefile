CC=g++
INCLUDE_DIR=./headers
CFLAGS=-I $(INCLUDE_DIR) -o ../bin/t_fsa.elf

TRANSITION_GRAPH_DIR=./tr_graph
TRANSITION_GRAPH_OBJS=$(TRANSITION_GRAPH_DIR)/TransitionGraph.o $(TRANSITION_GRAPH_DIR)/StateNode.o

LEXER_DIR=./lexer
LEXER_OBJS=$(LEXER_DIR)/Lexer.o

ENGINE_DIR=./engine
ENGINE_OBJS=$(ENGINE_DIR)/Engine.o

all: main

main: lexer transition_graph engine
	$(CC) main.cpp $(ENGINE_OBJS) $(LEXER_OBJS) $(TRANSITION_GRAPH_OBJS) $(CFLAGS)

.PHONY: lexer transition_graph engine
lexer:
	$(MAKE) -C ./lexer

transition_graph:
	$(MAKE) -C $(TRANSITION_GRAPH_DIR)

engine:
	$(MAKE) -C $(ENGINE_DIR)

run:
	../bin/t_fsa.elf

clean:
	find ./ -name "*.o" -exec rm {} \;
	rm ../bin/*.elf
