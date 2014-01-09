#set compiler
CC = g++
CFLAGS = -std=c++11 -Wall -c
OUTPUT_DIR = ./bin/
EXECUTABLE = notecard
MAIN = TestCardSet2

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OUTPUT_DIR)Card.o $(OUTPUT_DIR)CardSet.o $(OUTPUT_DIR)$(MAIN).o
	$(CC) $(OUTPUT_DIR)Card.o $(OUTPUT_DIR)CardSet.o $(OUTPUT_DIR)$(MAIN).o -o $(EXECUTABLE)

$(OUTPUT_DIR)Card.o: Card.cpp Card.h
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)Card.o Card.cpp

$(OUTPUT_DIR)CardSet.o: CardSet.cpp CardSet.h
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)CardSet.o CardSet.cpp

$(OUTPUT_DIR)$(MAIN).o: $(MAIN).cpp
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)$(MAIN).o $(MAIN).cpp

clean:
	rm -rf *.o
	rm $(EXECUTABLE)
