CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=
SOURCES=$(wildcard *.c) 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=qbonrails

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
    
.c.o: 
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm *.o
    