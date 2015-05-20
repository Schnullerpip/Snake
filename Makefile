#Makefile

#Compilervariablen
CC=g++
CFLAGS=-W -Wall -g 
CPFLAGS =-I.

#Hilfsvariablen
VIEW=TUI
PACKAGES=model model/cell model/field model/food model/snake view controller lock_distributor

TARGET=SnakeGame
OBJECTS=controller.o cell.o field.o  food.o position.o snake.o $(VIEW).o lock_distributor.o

.c.o:
	$(CC) $(CFLAGS) $(CPFLAGS) $@ -c 

.PHONY: all clean

all:
	for p in $(PACKAGES); do \
		(cd $$p && $(MAKE) $@); \
	done
	$(CC) $(CFLAGS) $(OBJECTS) $(TARGET).cpp -o $(TARGET) -lpthread

clean:
	rm -rf *.o $(TARGET)
	sudo rm /bin/snake
