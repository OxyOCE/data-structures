CC=gcc
CFLAGS=-W -Wall -pedantic -g
TARGET=test

OBJS=main.o mem.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c include/mem.h
	$(CC) $(CFLAGS) -c main.c

mem.o: mem.c include/mem.h
	$(CC) $(CFLAGS) -c mem.c

array-list.o: array-list.c include/array-list.h
	$(CC) $(CFLAGS) -c array-list.c
