CC=g++
BINARY=./p2.bin
SRC= p2.cpp
OPTIONS=-Wall -g -Werror
TEST=teste.in

all:
	@$(CC) $(SRC) -o $(BINARY) $(OPTIONS)
run:
	@$(BINARY)
test:
	@$(BINARY) < $(TEST)
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
