

CC=gcc
CFLAGS=-c -std=c99
LDFLAGS=
LIBS=-lncurses

SOURCES=menu_handlers.c menu_main.c main.c
OBJECTS=$(SOURCES:.c=.o)
HEADERS=menu_handlers.h menu_main.h
TARGET=bin_menu_test


all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	rm -rf *.o
	rm -rf $(TARGET)

