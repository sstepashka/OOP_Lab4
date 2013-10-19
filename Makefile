CC=gcc
CFLAGS=
LDFLAGS=-Wall
SOURCES=Box.c Composite.c Cyrcle.c Rect.c Shape.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=lab_4

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)