CC=g++
INCLUDE_DIR=./headers
CFLAGS=-I $(INCLUDE_DIR) -o ../bin/t_fsa.elf

TRANSITION_MATRIX_DIR=./transition_matrix
TRANSITION_MATRIX_OBJS=$(TRANSITION_MATRIX_DIR)/Transition.o $(TRANSITION_MATRIX_DIR)/TransitionRow.o $(TRANSITION_MATRIX_DIR)/TransitionMatrix.o

LEXER_DIR=./lexer
LEXER_OBJS=$(LEXER_DIR)/Lexer.o

ENGINE_DIR=./engine
ENGINE_OBJS=$(ENGINE_DIR)/Engine.o

all: main

main: lexer transition_matrix engine
	$(CC) main.cpp $(ENGINE_OBJS) $(LEXER_OBJS) $(TRANSITION_MATRIX_OBJS) $(CFLAGS)

lexer:
	$(MAKE) -I ./lexer

transition_matrix:
	$(MAKE) -I $(TRANSITION_MATRIX_DIR)

engine:
	$(MAKE) -I $(ENGINE_DIR)

run:
	../bin/t_fsa.elf

clean:
	find ./ -name "*.o" -exec rm {} \;
	rm ./bin/*.elf
