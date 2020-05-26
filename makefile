CC=gcc
CFLAGS=-W -Wall -pedantic -g
DIST=../dist

UNIT_TESTS=unit-tests

DEPS=$(wildcard include/*.h)
OBJS=array-list.o common.o mem.o quicksort.o simple-algorithms.o

$(UNIT_TESTS): unit-tests.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(DIST)/$(UNIT_TESTS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<
