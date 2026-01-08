CC=g++
LDFLAGS=-lm
CFLAGS=-std=c++20 -Wextra -Wall -Werror -pedantic
BASH=bash

ifeq ($(DEBUG),yes)
	CFLAGS += -g
	LDFLAGS +=
else
	CFLAGS += -O3 -DNDEBUG
	LDFLAGS +=
endif

EXEC=out
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

all:
ifeq ($(DEBUG),yes)
	@echo "Compilation en mode DEBUG"
else
	@echo "Compilation en mode RELEASE"
endif
	@$(MAKE) $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cc
	@$(CC) -o $@ -c $< $(CFLAGS)



.PHONY: clean mrproper run

run:
	@./$(EXEC) $(INPUT)

dgb:
	@gbd ./$(EXEC)

mem_check:
	@valgrind ./$(EXEC) 

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)

