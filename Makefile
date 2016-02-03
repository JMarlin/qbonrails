CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.c list.c lexer.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=qbonrails

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $(OBJECTS) -o $@
    
.c.o: 
    $(CC) $(CFLAGS) $< -o $@
    