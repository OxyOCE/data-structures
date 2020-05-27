#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/simple-algorithms.h"
#include "include/defs.h"

int main(int argc, char **argv)
{
    (void)argc;

    int array[] = {999, 1, 2, 3, 4, 5, 6, 7, 8, 999};
    long size = (long)(sizeof(array) / sizeof(array[0]));
    long idx;

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

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
