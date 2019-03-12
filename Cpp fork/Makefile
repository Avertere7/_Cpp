CC=g++
CFLAGS=-Wall -ansi -pedantic

EXECUTABLE=main

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -rfv *.o $(EXECUTABLE)
run: $(EXECUTABLE)
	./$(EXECUTABLE)

