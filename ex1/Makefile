CC=g++
BINARY=ex1.bin
SRC= ex1.cpp
OPTIONS=-Wall -g

all:
	@$(CC) $(SRC) -o $(BINARY) $(OPTIONS)
run:
	@$(BINARY)
debug:
	@$(CC) $(OPTIONS) $(SRC) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
