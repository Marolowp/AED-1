CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = programa
OBJS = main.o pilha.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c pilha.h
	$(CC) $(CFLAGS) -c main.c

pilha.o: pilha.c pilha.h
	$(CC) $(CFLAGS) -c pilha.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean