#include "include/quicksort.h"
#include "include/common.h"
#include "include/defs.h"

static long partition(int *array, int l, int r)
{
    long i, j, p, m = l + (r - l) / 2;

    if (array[m] < array[l]) {
        swap(array[l], array[m]);
    }
    if (array[r] < array[l]) {
        swap(array[l], array[r]);
    }
    if (array[m] < array[r]) {
        swap(array[m], array[r]);
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
        swap(&i, &j);
        i++;
        j--;
    }
}

int quicksort(int *array, long size, int l, int r)
{
    long p;

    if (l < 0 || r < 0 || l >= size || r >= size) {
        return INDEX_OUT_OF_BOUNDS;
    }

    if (l < r) {
        p = partition(array, l, r);
        quicksort(array, size, l, p);
        quicksort(array, size, p + 1, r);
    }

    return SUCCESS;
}
