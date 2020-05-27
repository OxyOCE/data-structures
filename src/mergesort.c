#include "include/mergesort.h"
#include "include/defs.h"

/*
    Mergesort works by dividing an array into subarrays recursively.
    Once the subarrays are 2 or 1 elements long, they are copied into temporary
    arrays and are merged back into the original array by comparing which of
    the temporary arrays' next elements is the smallest.
*/

static void merge(int *array, long l, long m, long r)
{

}

int mergesort(int *array, long size, int l, int r)
{
    // Neither index can be out of bounds
    if (l < 0 || r < 0 || l >= size || r >= size) {
        return INDEX_OUT_OF_BOUNDS;
    }

    // Base case (sub array is size 2 so no need to divide further)
    if (l < r) {
        // Find the midpoint
        long m = l + (r - l) / 2;

        // Define the lower subarrays recursively
        mergesort(array, size, l, m);
        // Define the lower upper subarrays recursively
        mergesort(array, size, m + 1, r);
        // Merge the subarrays back up the recursion leaving a sorted array
        merge(array, l, m, r);
    }

    return SUCCESS;
}
