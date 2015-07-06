CC=g++
INCLUDE_DIR=./headers
CFLAGS=-I $(INCLUDE_DIR) -o ../bin/t_fsa.elf

TRANSITION_GRAPH_DIR=./tr_graph
TRANSITION_GRAPH_OBJS=$(TRANSITION_GRAPH_DIR)/TransitionGraph.o $(TRANSITION_GRAPH_DIR)/StateNode.o

LEXER_DIR=./lexer
LEXER_OBJS=$(LEXER_DIR)/Lexer.o $(LEXER_DIR)/LexerSemanticCommand.o $(LEXER_DIR)/CharacterAccumulateCommand.o $(LEXER_DIR)/LexerControlCommand.o

ENGINE_DIR=./engine
ENGINE_OBJS=$(ENGINE_DIR)/Engine.o

PARSER_DIR=./parser
PARSER_OBJS=$(PARSER_DIR)/Parser.o

all: main

main: lexer parser transition_graph engine
	$(CC) main.cpp $(ENGINE_OBJS) $(LEXER_OBJS) $(TRANSITION_GRAPH_OBJS) $(CFLAGS)

.PHONY: lexer transition_graph engine parser
lexer:
	$(MAKE) -C ./lexer

transition_graph:
	$(MAKE) -C $(TRANSITION_GRAPH_DIR)

engine:
	$(MAKE) -C $(ENGINE_DIR)

parser:
	$(MAKE) -C $(PARSER_DIR)

run:
	../bin/t_fsa.elf

clean:
	find ./ -name "*.o" -exec rm {} \;
	rm ../bin/*.elf
