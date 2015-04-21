CC=g++
INCLUDE_DIR=../headers
CFLAGS=-I $(INCLUDE_DIR) -c -std=c++11
SEMANTIC_CMDS=CharacterAccumulateCommand.cpp LexerSemanticCommand.cpp LexerControlCommand.cpp

all: lexer lexer_sem
lexer: lexer_sem
	$(CC) Lexer.cpp $(CFLAGS)

lexer_sem:
	$(CC) $(SEMANTIC_CMDS) $(CFLAGS)

clean:
	rm *.o
