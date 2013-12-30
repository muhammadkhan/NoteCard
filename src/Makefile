#set compiler
CC = g++
CFLAGS = -std=c++11 -Wall -c
OUTPUT_DIR = ./bin/
EXECUTABLE = notecard

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OUTPUT_DIR)Card.o $(OUTPUT_DIR)CardSet.o $(OUTPUT_DIR)simulator.o
	$(CC) $(OUTPUT_DIR)Card.o $(OUTPUT_DIR)CardSet.o $(OUTPUT_DIR)simulator.o -o $(EXECUTABLE)

$(OUTPUT_DIR)Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)Card.o Card.cpp

$(OUTPUT_DIR)CardSet.o: CardSet.cpp CardSet.h
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)CardSet.o CardSet.cpp

$(OUTPUT_DIR)simulator.o: simulator.cpp
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)simulator.o simulator.cpp

clean:
	rm -rf *.o
	rm $(EXECUTABLE)
