#include <stddef.h>
#include "include/simple-algorithms.h"
#include "include/common.h"
#include "include/defs.h"

int insertion_sort(int *array, long size)
{
    int i, j;

    // If the array is zero-length or elementary, it is already sorted
    if (size > 1) {

        // Start at the second element and iterate through the whole array
        i = 1;
        while (i < size) {
            j = i++;
            /*
            Decrement j until the preceding element of array[j] is less than array[j].
            Swap the two indicies. Everything from j leftwards in now in sorted order.
            */
            while (j > 0 && array[j - 1] > array[j]) {
                swap(&array[j], &array[j - 1]);
                j--;
            }
        }
    }

    return SUCCESS;
}

long binary_search(int *array, long size, long l, long r, int elem)
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

long linear_search(int *array, long size, int elem, long start)
{
    long i;

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

long linear_search_ll(linked_list ll, int elem, long start)
{
    linked_list_node curr_node = ll->head;
    long curr_node_idx = 0;

    while (curr_node != NULL) {
        if (curr_node->data == elem && curr_node_idx >= start) {
            return curr_node_idx;
        }

        curr_node = curr_node->next;
        curr_node_idx++;
    }

    return NOT_FOUND;
}
