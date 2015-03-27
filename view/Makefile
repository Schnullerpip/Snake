#Makefile

#Compilervariablen
CC=g++
CFLAGS=-W -Wall -g -lpthread
LDFLAGS=-I.

#Hilfsvariablen
TARGET=TUI.o
SOURCE=$(TARGET:.o=.cpp)

#Ziele
.PHONY: all clean

all: 
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCE) -c -o ../$(TARGET)

clean:
	rm -rf *.o *.swp

