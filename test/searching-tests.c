#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/simple-algorithms.h"
#include "include/defs.h"

int main(int argc, char **argv)
{
    (void)argc;

    int array[] = {999, 1, 2, 3, 4, 5, 6, 7, 8, 999};
    int elem;
    long size = (long)(sizeof(array) / sizeof(array[0]));
    long idx;
    linked_list ll;

    // Testing linear search
    assert((idx = linear_search(array, size, 999, 0)) == 0);
    assert(array[idx] == 999);

    assert((idx = linear_search(array, size, 999, 1)) == 9);
    assert(array[idx] == 999);

    // Bounds checking
    assert(linear_search(array, size, 999, -1) == 0);
    assert(linear_search(array, size, 999, 10) == NOT_FOUND);

    // Testing binary search
    assert((idx = binary_search(array, size, 0, size - 1, 999)) != NOT_FOUND);
    assert(array[idx] == 999);

    // Bounds checking
    assert(binary_search(array, size, 0, size, 999) == INDEX_OUT_OF_BOUNDS);
    assert(binary_search(array, size, -1, size - 1, 999) == INDEX_OUT_OF_BOUNDS);

    // Testing linked list linear_search
    ll = linked_list_new();
    for (idx = 0; idx < size; idx++) {
        linked_list_append(ll, array[idx]);
    }

    assert((idx = linear_search_ll(ll, 999, 0)) == 0);
    assert(linked_list_get(ll, &elem, idx) == SUCCESS && elem == 999);

    assert((idx = linear_search_ll(ll, 999, 1)) == 9);
    assert(linked_list_get(ll, &elem, idx) == SUCCESS && elem == 999);

    // Bounds checking
    assert(linear_search_ll(ll, 999, -1) == 0);
    assert(linear_search_ll(ll, 999, 10) == NOT_FOUND);

    linked_list_free(ll);

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
