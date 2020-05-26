#include <stdlib.h>
#include <stdio.h>
#include "include/quicksort.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    int *heap_array;
    int test_array[] = {3, 4, 4, 5, 10, 9, 4, 1, 2, 1, 9, 5, 8, 7, 10, 7};
    int test_array_2[] = {2, 1, 4, 3};
    int test_array_sorted[] = {1, 1, 2, 3, 4, 4, 4, 5, 5, 7, 7, 8, 9, 9, 10, 10};
    int test_array_2_sorted[] = {1, 2, 3, 4};
    long test_array_size = (long)(sizeof(test_array) / sizeof(test_array[0]));
    long test_array_2_size = (long)(sizeof(test_array_2) / sizeof(test_array_2[0]));

    heap_array = emalloc(16 * sizeof heap_array[0]);

    for (i = 0; i < test_array_size; i++) {
        heap_array[i] = test_array[i];
    }

    quicksort(heap_array, test_array_size, 0, test_array_size - 1);

    for (i = 0; i < test_array_size; i++) {
        assert(heap_array[i] == test_array_sorted[i]);
    }

    for (i = 0; i < test_array_2_size; i++) {
        heap_array[i] = test_array_2[i];
    }

    quicksort(heap_array, test_array_2_size, 0, test_array_2_size - 1);

    for (i = 0; i < test_array_2_size; i++) {
        assert(heap_array[i] == test_array_2_sorted[i]);
    }

    free(heap_array);

    return EXIT_SUCCESS;
}
