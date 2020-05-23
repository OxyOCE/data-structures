CC=gcc
CFLAGS=-W -Wall -pedantic -g
TARGET=test

OBJS=main.o mem.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

mem.o: mem.c
	$(CC) $(CFLAGS) -c mem.c
