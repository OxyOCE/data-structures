#include "include/heapsort.h"
#include "include/common.h"
#include "include/defs.h"

/*
Heapsort takes advantage of the fact that heaps can be easily represented in an array.
A heap is a complete binary tree with the property that all child nodes are less
than their parent node, therefore if we remove the root node and rebuild the heap
until it is empty, the root nodes will be removed in sorted order. We can represent
the heap such that if:

parent_index = i; then
left_child_index  = 2 * i + 1; and
right_child_index = 2 * i + 2

With this, we can swap the element at 0 with the end of the heap (removing the root node),
then reduce the heap size by one and rebuild the heap. Once the heap is empty, the array
is in sorted order.
*/

static void sift_down(int *array, long start, long end)
{
    int root, l_child, swap_idx;

    root = start;
    while (2 * root + 1 <= end) {
        l_child = 2 * root + 1;
        swap_idx = root;

        // If the root is smaller than the left child, mark them to be swapped.
        if (array[swap_idx] < array[l_child]) {
            swap_idx = l_child;
        }
        // If the root is smaller than the right child, mark them to be swapped.
        if (l_child + 1 <= end && array[swap_idx] < array[l_child + 1]) {
            swap_idx = l_child + 1;
        }
        // If the root is the largest, the subheap is in heap order
        if (swap_idx == root) {
            return;
        } else {
            /*
            Swap the marked child with the root.
            Check that the other child was not larger than the swapped child.
            */
            swap(&array[root], &array[swap_idx]);
            root = swap_idx;
        }
    }
}

// Before we can use heapsort, we first need to transform the array into a heap
static void heapify(int *array, long size)
{
    int start;

    // Start at the last parent index
    start = (size - 2) / 2;
    while (start >= 0) {
        // Ensure that the root, left child and right child are in heap order
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
