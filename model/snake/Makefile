#Makefile

#Compilervariablen
CC=g++
CFLAGS=-W -Wall -g
LDFLAGS=-I.

#Hilfsvariablen
TARGET=snake.o
SOURCE=$(TARGET:.o=.cpp)

#Ziele
.PHONY: all clean

all: 
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCE) -c -o ../../$(TARGET)

clean:
	rm -rf *.o *.swp

