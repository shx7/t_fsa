CC=g++
INCLUDE_DIR=../headers
CFLAGS=-I $(INCLUDE_DIR) -c

all: lexer lexer_sem
lexer: lexer_sem
	$(CC) Lexer.cpp $(CFLAGS)

lexer_sem:
	$(CC) LexerSemanticCommand.cpp $(CFLAGS)

clean:
	rm *.o
