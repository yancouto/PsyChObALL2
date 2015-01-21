# Assumes SFML folder is in the same directory as psycho's
CC=g++
CFLAGS=-I../../SFML-2.2/include/ -c -O2 -Wall
LDFLAGS=-L../../SFML-2.2/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all: psy2

psy2: main.o
	$(CC) $^ -o $@ $(LDFLAGS)

main.o: main.cc main.h
	$(CC) main.cc $(CFLAGS)

clean:
	del *.o