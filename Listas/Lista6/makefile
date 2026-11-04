CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = programa
OBJS = main.o fila.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c fila.c
	$(CC) $(CFLAGS) -c main.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean