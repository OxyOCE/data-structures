#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/simple-algorithms.h"
#include "include/defs.h"
#include "include/linked-list.h"

int main(int argc, char **argv)
{
    (void)argc;

    int array[] = {999, 0, 999, 0, 999};
    int array_binary_search[] = {0, 2, 4, 6, 8, 10, 12, 14, 16};
    long size = (long)(sizeof(array) / sizeof(array[0]));
    long size_binary_search = (long)(sizeof(array_binary_search) / sizeof(array_binary_search[0]));
    long i;
    linked_list ll;

    ll = linked_list_new();

    assert(search_ll(ll, 999, 0) == NOT_FOUND);

    for (i = 0; i < size; i++) {
        linked_list_append(ll, array[i]);
    }

    assert(search_ll(ll, 999, -1) == 0);
    assert(search_ll(ll, 999, 0) == 0);
    assert(search_ll(ll, 999, 1) == 2);
    assert(search_ll(ll, 999, 2) == 2);
    assert(search_ll(ll, 999, 3) == 4);
    assert(search_ll(ll, 999, 4) == 4);
    assert(search_ll(ll, 999, 5) == NOT_FOUND);

    assert(linear_search(array, 0, 999, 0) == NOT_FOUND);
    assert(linear_search(array, size, 999, -1) == 0);
    assert(linear_search(array, size, 999, 0) == 0);
    assert(linear_search(array, size, 999, 1) == 2);
    assert(linear_search(array, size, 999, 2) == 2);
    assert(linear_search(array, size, 999, 3) == 4);
    assert(linear_search(array, size, 999, 4) == 4);
    assert(linear_search(array, size, 999, 5) == NOT_FOUND);

    // Reference: https://www.digizol.com/2013/08/java-binary-search-recursive-testcases.html
    assert(binary_search(array_binary_search, size_binary_search, 0, size_binary_search - 1, 9) == NOT_FOUND);
    assert(binary_search(array_binary_search, size_binary_search, 0, size_binary_search - 1, 0) == 0);
    assert(binary_search(array_binary_search, size_binary_search, 0, size_binary_search - 1, 8) == 4);
    assert(binary_search(array_binary_search, size_binary_search, 0, size_binary_search - 1, 16) == 8);

    linked_list_free(ll);

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
