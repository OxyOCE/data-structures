#include "include/heapsort.h"
#include "include/common.h"
#include "include/defs.h"

static void sift_down(int *array, long start, long end)
{
    int root, l_child, swap_idx;

    root = start;
    while (2 * root + 1 <= end) {
        l_child = 2 * root + 1;
        swap_idx = root;

        if (array[swap_idx] < array[l_child]) {
            swap_idx = l_child;
        }
        if (l_child + 1 <= end && array[swap_idx] < array[l_child + 1]) {
            swap_idx = l_child + 1;
        }
        if (swap_idx == root) {
            return;
        } else {
            swap(&array[root], &array[swap_idx]);
            root = swap_idx;
        }
    }
}

static void heapify(int *array, long size)
{
    int start;

    start = (size - 2) / 2;
    while (start >= 0) {
        sift_down(array, start--, size - 1);
    }
}

int heapsort(int *array, long size)
{
    int end;

    // Transform the array into a heap data structure
    heapify(array, size);

    /*
    Pop the root (largest) node and move it to the end, rebuild the heap, and
    repeat until the heap is empty.
    */
    end = size - 1;
    while (end > 0) {
        swap(&array[end--], &array[0]);
        sift_down(array, 0, end);
    }

    return SUCCESS;
}
