CC = gcc
CFLAGS = `pkg-config --cflags gobject-2.0`
LIBS = `pkg-config --libs gobject-2.0`

all: main

main: main.c point.o
    $(CC) $(CFLAGS) -o main main.c point.o $(LIBS)

point.o: point.c point.h
    $(CC) $(CFLAGS) -c point.c $(LIBS)

clean:
    rm -f *.o main
