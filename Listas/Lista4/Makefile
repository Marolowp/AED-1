CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = programa
OBJS = main.o listaEncadeada.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c listaEncadeada.h
	$(CC) $(CFLAGS) -c main.c

listaEncadeada.o: listaEncadeada.c listaEncadeada.h
	$(CC) $(CFLAGS) -c listaEncadeada.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean