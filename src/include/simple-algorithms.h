#ifndef SIMPLE_ALGORITHMS_H_
#define SIMPLE_ALGORITHMS_H_

#include "linked-list.h"

extern int  insertion_sort(int *array, long size);
extern long binary_search(int *array, long size, long l, long r, int elem);
extern long linear_search(int *array, long size, int elem, long start);
extern long search_ll(linked_list ll, int elem, long start);

#endif
