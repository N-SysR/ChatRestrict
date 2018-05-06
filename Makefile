CC=g++
CXXFLAGS= -Wall -Werror -Wextra -std=c++17 -pedantic
VPATH=./src
OBJS= main.o
BIN=main

$(BIN):$(OBJS)

all: $(BIN)

clean:
	$(RM) main *.o
