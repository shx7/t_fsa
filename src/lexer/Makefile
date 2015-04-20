CC=g++
INCLUDE_DIR=../headers
CFLAGS=-I $(INCLUDE_DIR) -c
SEMANTIC_CMDS=CharacterAccumulateCommand.cpp LexerSemanticCommand.cpp

all: lexer lexer_sem
lexer: lexer_sem
	$(CC) Lexer.cpp $(CFLAGS)

lexer_sem:
	$(CC) $(SEMANTIC_CMDS) $(CFLAGS)

clean:
	rm *.o
