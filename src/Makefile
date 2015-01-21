# Assumes SFML folder is in the same directory as psycho's
CC=g++
CFLAGS=-I../../SFML-2.2/include/ -c -Wall
LDFLAGS=-L../../SFML-2.2/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
DEBUG = false

# If SystemRoot, Windows; Else *NIX.
ifdef SystemRoot
  # This means we're dealiing with Windows.
  CLEAN = del *.o *.exe
else
  # This means we're dealing with a *NIX system.
  CLEAN = rm *.o psy2
endif

# Sets whether to use DEBUG or not.
ifeq ($(DEBUG), true)
  CFLAGS += -g
else
  CFLAGS += -O2
endif

all: psy2

psy2: main.o
	$(CC) $^ -o $@ $(LDFLAGS)

main.o: main.cc main.h
	$(CC) main.cc $(CFLAGS)

clean:
	$(CLEAN)
