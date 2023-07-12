CC = g++
CFLAGS = -Wall -Wextra  -pedantic -std=c++14 -Iinclude -g
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = bin/main

TEST_SOURCES = $(filter-out src/main.cpp, $(SOURCES)) $(wildcard test/*.cpp) 
TEST_LIB = $(wildcard lib/catch2/*.cpp)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o) $(TEST_LIB:.cpp=.o)
TEST_EXECUTABLE = bin/test

all: $(EXECUTABLE) $(TEST_EXECUTABLE)

test: $(TEST_EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run-test
run-test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(TEST_OBJECTS) $(TEST_EXECUTABLE)

.PHONY: clean-doc
clean-doc:
	rm -rf ./doc/*

.PHONY: doc
doc:
	doxygen Doxyfile
