CC=gcc
CFLAGS=-W -Wall -pedantic -g
TARGET=test

OBJS=main.o array-list.o mem.o sort-and-search.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c include/array-list.h include/defs.h include/mem.h include/sort-and-search.h
	$(CC) $(CFLAGS) -c main.c

mem.o: mem.c include/mem.h
	$(CC) $(CFLAGS) -c mem.c

array-list.o: array-list.c include/array-list.h include/defs.h include/mem.h include/sort-and-search.h
	$(CC) $(CFLAGS) -c array-list.c

sort-and-search.o: sort-and-search.c include/sort-and-search.h include/defs.h
	$(CC) $(CFLAGS) -c sort-and-search.c
