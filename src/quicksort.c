#include "include/quicksort.h"
#include "include/common.h"
#include "include/defs.h"

static long partition(int *array, int l, int r)
{
    long i, j, p, m = l + (r - l) / 2;

    /*
    "Median of three" pivot selection - the median of array[l], array[m] and array[r].
    This significantly reduces the likelihood of quicksort degrading to quadratic performance.
    */
    if (array[m] < array[l]) {
        swap(&array[l], &array[m]);
    }
    if (array[r] < array[l]) {
        swap(&array[l], &array[r]);
    }
    if (array[m] < array[r]) {
        swap(&array[m], &array[r]);
    }

    // The median is swapped to the rightmost element
    p = array[r];
    i = l;
    j = r;

    /*
    The aim of partitioning is to place all the elements less than the pivot
    to the left of the pivot and all of the elements greater than the pivot
    right of the pivot. Quicksort is then called recursively on the two formed subarrays.
    Once the recursion is complete, a sorted array remains.

    for (;;) is equivalent to while (true) in other languages
    */
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
        swap(&array[i], &array[j]);
        i++;
        j--;
    }
}

int quicksort(int *array, long size, int l, int r)
{
    long p;

    // Neither index can be out of bounds
    if (l < 0 || r < 0 || l >= size || r >= size) {
        return INDEX_OUT_OF_BOUNDS;
    }

    // Base case (sub array is size 1 so no need to sort)
    if (l < r) {
        // Partition the array (Hoare partition scheme)
        p = partition(array, l, r);
        // Quicksort the lower subarray
        quicksort(array, size, l, p);
        // Quicksort the upper subarray
        quicksort(array, size, p + 1, r);
    }

    return SUCCESS;
}
