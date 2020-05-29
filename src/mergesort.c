#include <stddef.h>
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

int msort(int *array, long size, int l, int r)
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
        msort(array, size, l, m);
        // Define the lower upper subarrays recursively
        msort(array, size, m + 1, r);
        // Merge the subarrays back up the recursion leaving a sorted array
        merge(array, l, m, r);
    }

    return SUCCESS;
}

static linked_list_node merge_ll(linked_list_node l, linked_list_node r)
{
    if (l == NULL) {
        return r;
    }

    if (r == NULL) {
        return l;
    }

    if (l->data < r->data) {
        l->next = merge_ll(l->next, r);
        l->next->prev = l;
        l->prev = NULL;
        return l;
    } else {
        r->next = merge_ll(l, r->next);
        r->next->prev = r;
        r->prev = NULL;
        return r;
    }
}

static linked_list_node bisect(linked_list_node l)
{
    linked_list_node temp, s = l, d = l;

    while (d-> next != NULL && d->next->next != NULL) {
        d = d->next->next;
        s = s->next;
    }

    temp = s->next;
    s->next = NULL;
    return temp;
}

static linked_list_node msort_ll_inner(linked_list_node l)
{
    linked_list_node r;

    if (l == NULL || l->next == NULL) {
        return l;
    }

    r = bisect(l);
    l = msort_ll_inner(l);
    r = msort_ll_inner(r);

    return merge_ll(l, r);
}

// Reference: https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/
void msort_ll(linked_list ll)
{
    linked_list_node head, curr_node;

    head = ll->head;
    ll->head = msort_ll_inner(head);

    curr_node = ll->head;
    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }
    ll->tail = curr_node;
}
