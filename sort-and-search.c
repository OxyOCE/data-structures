#include "include/sort-and-search.h"
#include "include/defs.h"

static int bounds_check(int size, int l, int r)
{
    if (l < 0 || r < 0 || l >= size || r >= size) {
        return INDEX_OUT_OF_BOUNDS;
    }

    return SUCCESS;
}

static void swap(int *array, long l, long r)
{
    int tmp = array[l];
    array[l] = array[r];
    array[r] = tmp;
}

static long partition(int *array, int l, int r)
{
    long i, j, p, m = l + (r - l) / 2;

    if (array[m] < array[l]) {
        swap(array, l, m);
    }
    if (array[r] < array[l]) {
        swap(array, l, r);
    }
    if (array[m] < array[r]) {
        swap(array, m, r);
    }

    p = array[r];
    i = l;
    j = r;

    for (;;) {
        while (array[i] < p) {
            i++;
        }
        while (array[j] > p) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(array, i, j);
        i++;
        j--;
    }
}

int quicksort(int *array, long size, int l, int r)
{
    long p;

    if (bounds_check(size, l, r) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    if (l < r) {
        p = partition(array, l, r);
        quicksort(array, size, l, p);
        quicksort(array, size, p + 1, r);
    }

    return SUCCESS;
}

int linear_search(int *array, long size, int elem, long start)
{
    int i;

    if (start < 0) {
        i = 0;
    } else {
        i = start;
    }

    for (; i < size; i++) {
        if (array[i] == elem) {
            return i;
        }
    }

    return NOT_FOUND;
}

int binary_search(int *array, long size, long l, long r, int elem)
{
    long m;

    if (bounds_check(size, l, r) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    if (l <= r) {
        m = l + (r - l) / 2;

        if (array[m] == elem) {
            return m;
        }

        if (array[m] > elem) {
            return binary_search(array, size, l, m - 1, elem);
        }

        return binary_search(array, size, m + 1, r, elem);
    }

    return NOT_FOUND;
}
