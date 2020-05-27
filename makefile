CC=gcc
CFLAGS=-W -Wall -pedantic -g
DIST=../dist

DEPS=$(wildcard include/*.h)
OBJS=array-list.o common.o mem.o quicksort.o mergesort.o simple-algorithms.o

$(TEST): $(TEST).o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(DIST)/$(TEST)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<
