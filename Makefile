CC=gcc
CFLAGS=
LDFLAGS=-Wall
SOURCES=sources/Box.c sources/Composite.c sources/Cyrcle.c sources/Rect.c sources/Shape.c sources/main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=lab_4

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)