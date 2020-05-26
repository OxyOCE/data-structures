CC=gcc
CFLAGS=-W -Wall -pedantic -g
TARGET=test

OBJS=main.o array-list.o common.o mem.o quicksort.o simple-algorithms.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

main.o: main.c include/array-list.h include/defs.h include/mem.h include/quicksort.h include/simple-algorithms.h
	$(CC) $(CFLAGS) -c main.c

array-list.o: array-list.c include/array-list.h include/defs.h include/mem.h
	$(CC) $(CFLAGS) -c array-list.c

common.o: common.c include/common.h
	$(CC) $(CFLAGS) -c common.c

mem.o: mem.c include/mem.h
	$(CC) $(CFLAGS) -c mem.c

quicksort.o: quicksort.c include/quicksort.h include/common.h include/defs.h
	$(CC) $(CFLAGS) -c quicksort.c

simple-algorithms.o: simple-algorithms.c include/simple-algorithms.h include/defs.h
	$(CC) $(CFLAGS) -c simple-algorithms.c

clean:
	rm -rf $(OBJS) $(TARGET)
