CC=g++

all: main

main: lexer
	$(CC) main.cpp Lexer.o -o lab.elf

lexer:
	$(CC) Lexer.cpp -c

clean:
	rm *.o
	rm *.elf
