#Makefile

#Compilervariablen
CC=g++
CFLAGS=-W -Wall -g
CPFLAGS =-I.

#Hilfsvariablen
VIEW=TUI
PACKAGES=model model/cell model/field model/food model/snake view controller

TARGET=SnakeGame
OBJECTS=controller.o cell.o field.o  food.o position.o snake.o $(VIEW).o

.c.o:
	$(CC) $(CFLAGS) $(CPFLAGS) $@ -c 

.PHONY: all clean

all:
	for p in $(PACKAGES); do \
		(cd $$p && $(MAKE) $@); \
	done
	$(CC) $(CFLAGS) $(OBJECTS) $(TARGET).cpp -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
