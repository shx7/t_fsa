CC=g++

all: main

main: lexer
	$(CC) main.cpp Lexer.o -o t_fsa.elf

lexer:
	$(CC) Lexer.cpp -c

clean:
	rm *.o
	rm *.elf
