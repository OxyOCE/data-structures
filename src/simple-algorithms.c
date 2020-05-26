#include "include/simple-algorithms.h"
#include "include/defs.h"

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

    if (l < 0 || r < 0 || l >= size || r >= size) {
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
