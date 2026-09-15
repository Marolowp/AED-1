CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = programa
OBJS = main.o personagem.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.c personagem.h
	$(CC) $(CFLAGS) -c main.c

personagem.o: personagem.c personagem.h
	$(CC) $(CFLAGS) -c personagem.c

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean