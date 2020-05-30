CC=gcc
CFLAGS=-W -Wall -pedantic -g
DIST=../dist

DEPS=$(wildcard include/*.h)
OBJS=array-list.o common.o heapsort.o linked-list.o mem.o mergesort.o queue.o quicksort.o simple-algorithms.o stack.o

$(TEST): $(TEST).o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(DIST)/$(TEST)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<
