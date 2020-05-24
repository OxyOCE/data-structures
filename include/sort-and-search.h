#ifndef SORT_AND_SEARCH_H_
#define SORT_AND_SEARCH_H_

extern int quicksort(int *array, long size, int l, int r);
extern int linear_search(int *array, long size, int elem, long start);
extern int binary_search(int *array, long size, long l, long r, int elem);

#endif
