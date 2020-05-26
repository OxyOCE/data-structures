#include "include/simple-algorithms.h"
#include "include/defs.h"

int linear_search(int *array, long size, int elem, long start)
{
    int i;

    // Can't have negative indicies so start at 0 minimum
    if (start < 0) {
        i = 0;
    } else {
        i = start;
    }

    /*
    Search the whole array for the target element

    i is already initialised above
    */
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

    // Neither index can be out of bounds
    if (l < 0 || r < 0 || l >= size || r >= size) {
        return INDEX_OUT_OF_BOUNDS;
    }

    // Base case (i.e. the search has converged to a single element)
    if (l <= r) {
        // Find the mid point
        m = l + (r - l) / 2;

        // If the middle element is the target element, return the index
        if (array[m] == elem) {
            return m;
        }

        // If the middle element is greater than the target element, search the lower half of the subarray
        if (array[m] > elem) {
            return binary_search(array, size, l, m - 1, elem);
        }

        // If the middle element is less than the target element, search the upper half of the subarray
        return binary_search(array, size, m + 1, r, elem);
    }

    // Otherwise the target element is not in the array
    return NOT_FOUND;
}
