CC=g++
# Assumes SFML folder is in the same directory as psycho's
SFML_PATH=../SFML-2.2
CFLAGS=-I$(SFML_PATH)/include/ -I. -c -Wall -std=gnu++11
LDFLAGS=-L$(SFML_PATH)/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lm
DEBUG = false

# Sets whether to use DEBUG or not.
ifeq ($(DEBUG), true)
  CFLAGS += -g
else
  CFLAGS += -O2
endif


# Testing Stuff
GTEST_PATH=../gtest-1.7.0
GFLAGS=-I$(GTEST_PATH)/include $(CFLAGS)
GLDFLAGS=-L$(GTEST_PATH)/lib $(LDFLAGS) -lgtest

# If SystemRoot, Windows; Else *NIX.
ifdef SystemRoot
  # This means we're dealing with Windows.
  CLEAN = del *.o *.exe
else
  # This means we're dealing with a *NIX system.
  CLEAN = rm *.o psy2 test
  GLDFLAGS += -pthread
endif

# All non-test files (except main)
DEPS=psycho2.o scene.o task.o main_menu.o
# Tests
TESTS=psycho2_test.o scene_test.o task_test.o main_menu_test.o

# Adding a file instructions:
# When you add a file, be sure to add its .o to DEPS
# And make its .o target, that probably looks like this:
#   file.o: file.cc file.h (other dependencies)
#     $(CC) $< $(CFLAGS)
# And its test .o to TESTS, and the target should look like this:
#   file_test.o: file_test.cc file.h (file.h dependencies)
#     $(CC) $< $(GFLAGS)
# That's it! :D
# Is this the best way to do this? Probably not.
# Do I care? Probably not.


all: psy2

psy2: $(DEPS) main.o
	$(CC) $^ -o $@ $(LDFLAGS)

test: $(DEPS) $(TESTS) gtest_main.o
	$(CC) $^ -o $@ $(GLDFLAGS)

gtest_main.o:
	$(CC) $(GTEST_PATH)/src/gtest_main.cc -c -std=gnu++0x -O2 -I$(GTEST_PATH)/include

# Root related compilations. //

main.o: main.cc
	$(CC) $< $(CFLAGS)

psycho2.o: psycho2.cc psycho2.h
	$(CC) $< $(CFLAGS)

psycho2_test.o: psycho2_test.cc psycho2.h
	$(CC) $< $(GFLAGS)

# // Root related compilations.
# Engine related compilations. //

scene.o: engine/scene.cc engine/scene.h
	$(CC) $< $(CFLAGS)

scene_test.o: engine/scene_test.cc engine/scene.h
	$(CC) $< $(GFLAGS)

task.o: engine/task.cc engine/task.h
	$(CC) $< $(CFLAGS)

task_test.o: engine/task_test.cc engine/task.h
	$(CC) $< $(GFLAGS)

# // Engine related compilations.
# Menu related compilations. //

main_menu.o: menus/main_menu.cc menus/main_menu.h
	$(CC) $< $(CFLAGS)

main_menu_test.o: menus/main_menu_test.cc menus/main_menu.h
	$(CC) $< $(GFLAGS)

# // Menu related compilations.

.PHONY: clean
clean:
	$(CLEAN)
