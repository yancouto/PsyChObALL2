CC=g++
# Assumes SFML folder is in the same directory as psycho's
SFML_PATH=../SFML-2.2

# TMXLoader folder
TMXLOADER_PATH = ../tmxloader

CFLAGS=-I$(SFML_PATH)/include/ -I$(TMXLOADER_PATH)/include/ -I. -c -Wno-unused-function -Wall -std=gnu++11
LDFLAGS=-L$(SFML_PATH)/lib/ -L$(TMXLOADER_PATH)/lib/ -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lpugi -ltmx-loader -lz -lm
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
DEPS=manager.o state.o task.o main_menu.o body.o player.o globals.o math.o color.o splash_screen.o
# Tests
TESTS=manager_test.o state_test.o task_test.o main_menu_test.o body_test.o player_test.o globals_test.o math_test.o color_test.o splash_screen_test.o

# Adding a file instructions:
# When you add a file, be sure to add its .o to DEPS
# And make its .o target, that probably looks like this:
#   file.o: file.cc file.h (other dependencies)
#     $(CC) $< $(CFLAGS)
# And its test .o to TESTS, and the target should look like this:
#   file_test.o: file_test.cc file.o
#     $(CC) $< $(GFLAGS)
# That's it! :D
# Is this the best way to do this? Probably not.
# Do I care? Probably not.

all: psy2 test

game: psy2

psy2: $(DEPS) main.o
	$(CC) $^ -o $@ $(LDFLAGS)

test: $(TESTS) gtest_main.o
	$(CC) $^ -o $@ $(GLDFLAGS)

gtest_main.o:
	$(CC) $(GTEST_PATH)/src/gtest_main.cc -c -std=gnu++0x -O2 -I$(GTEST_PATH)/include

# Root related compilations. //

main.o: main.cc system/manager.h menu/main_menu.h menu/splash_screen.h engine/state.h entities/player.h engine/task.h engine/body.h utils/color.h
	$(CC) $< $(CFLAGS)

# // Root related compilations.
# System related compilations. //

manager.o: system/manager.cc manager.h
	$(CC) $< $(CFLAGS)

manager.h: system/manager.h

manager_test.o: system/manager_test.cc manager.o
	$(CC) $< $(GFLAGS)

globals.o: system/globals.cc globals.h
	$(CC) $< $(CFLAGS)

globals.h: system/globals.h

globals_test.o: system/globals_test.cc globals.o
	$(CC) $< $(GFLAGS)

# // System related compilations.
# Engine related compilations. //

state.o: engine/state.cc state.h
	$(CC) $< $(CFLAGS)

state.h: engine/state.h task.h

state_test.o: engine/state_test.cc state.o
	$(CC) $< $(GFLAGS)

task.o: engine/task.cc task.h
	$(CC) $< $(CFLAGS)

task.h: engine/task.h

task_test.o: engine/task_test.cc task.o
	$(CC) $< $(GFLAGS)

body.o: engine/body.cc body.h
	$(CC) $< $(CFLAGS)

body.h: engine/body.h

body_test.o: engine/body_test.cc body.o
	$(CC) $< $(GFLAGS)

# // Engine related compilations.
# Menu related compilations. //

main_menu.o: menu/main_menu.cc main_menu.h task.h color.h globals.h manager.h
	$(CC) $< $(CFLAGS)

main_menu.h: state.h player.h menu/main_menu.h

main_menu_test.o: menu/main_menu_test.cc main_menu.o
	$(CC) $< $(GFLAGS)

splash_screen.o: menu/splash_screen.cc splash_screen.h task.h manager.h main_menu.h
	$(CC) $< $(CFLAGS)

splash_screen.h: state.h menu/splash_screen.h

splash_screen_test.o: menu/splash_screen_test.cc splash_screen.o
	$(CC) $< $(GFLAGS)

# // Menu related compilations.
# Entities related compilations.

player.o: entities/player.cc math.h globals.h
	$(CC) $< $(CFLAGS)

player.h: body.h color.h entities/player.h

player_test.o: entities/player_test.cc player.o
	$(CC) $< $(GFLAGS)

# // Entities related compilations.
# Utils related compilations.

math.o: utils/math.cc math.h
	$(CC) $< $(CFLAGS)

math.h: utils/math.h

math_test.o: utils/math_test.cc math.o
	$(CC) $< $(GFLAGS)

color.o: utils/color.cc color.h math.h
	$(CC) $< $(CFLAGS)

color.h: utils/color.h

color_test.o: utils/color_test.cc color.o
	$(CC) $< $(GFLAGS)

# // Utils related compilations.

.PHONY: clean
clean:
	$(CLEAN)
