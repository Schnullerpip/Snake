#Makefile

#Compilervariablen
CC=g++
CFLAGS=-W -Wall
LDFLAGS=-I.

#Hilfsvariablen
TARGET=food.o
SOURCE=$(TARGET:.o=.cpp)

#Ziele
.PHONY: all clean

all: 
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCE) -c -o ../../$(TARGET)

clean:
	rm -rf *.o *.swp

