CC=g++
BINARY=./ex1.bin
SRC= ex1.cpp
OPTIONS=-Wall -g -Werror
TEST=casos/2.in
TEST=teste.in

all:
	@$(CC) $(SRC) -o $(BINARY) $(OPTIONS)
run:
	@$(BINARY) #< $(TEST)
valgrind:
	@$(CC) $(OPTIONS) $(SRC) -o $(BINARY)
	@valgrind --leak-check=yes $(BINARY)
fsanitize:
	@$(CC) $(OPTIONS) $(SRC) -fsanitize=address -o $(BINARY)
	@$(BINARY) < $(TEST)
zip:
	@zip -r trab.zip $(SRC) Makefile
clean:
	@rm trab.zip
	@rm $(BINARY)
