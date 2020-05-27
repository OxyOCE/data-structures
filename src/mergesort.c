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
    long i, j, k;
    long l_size = m - l + 1, r_size = r - m;
    int l_array[l_size], r_array[r_size];

    // Copy the defined subarrays into temporary arrays
    for (i = 0; i < l_size; i++) {
        l_array[i] = array[l + i];
    }
    for (j = 0; j < r_size; j++) {
        r_array[j] = array[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    // Merge the next smallest element in either array
    while (i < l_size && j < r_size) {
        if (l_array[i] <= r_array[j]) {
            array[k++] = l_array[i++];
        } else {
            array[k++] = r_array[j++];
        }
    }

    // Append any remaining elements
    while (i < l_size) {
        array[k++] = l_array[i++];
    }
    while(j < r_size) {
        array[k++] = r_array[j++];
    }
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
