#include <stdlib.h>
#include <assert.h>
#include "include/array-list.h"
#include "include/defs.h"
#include "include/mem.h"
#include "include/sort-and-search.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    long default_al_capacity, idx;
    int i, errno, elem;

    // Unit tests for mem.c
    // -------------------------------------------------------------------------
    void *ptr = emalloc(1);
    ptr = erealloc(ptr, 1);
    free(ptr);

    // Unit tests for array-list.c
    // -------------------------------------------------------------------------
    array_list al = array_list_new();
    default_al_capacity = al->capacity;

    // Can't delete from an empty list
    assert((errno = array_list_delete(al, &elem, al->size)) == INDEX_OUT_OF_BOUNDS);

    // Testing upscaling
    for (i = 0; i < default_al_capacity; i++) {
        array_list_append(al, i);
    }

    assert(al->capacity == default_al_capacity);
    assert(al->size == default_al_capacity);

    array_list_append(al, default_al_capacity);

    assert(al->capacity == default_al_capacity * 2);
    assert(al->size == default_al_capacity + 1);

    // Testing get
    assert((errno = array_list_get(al, &elem, 0)) == SUCCESS && elem == 0);
    assert((errno = array_list_get(al, &elem, 1)) == SUCCESS && elem == 1);
    assert((errno = array_list_get(al, &elem, default_al_capacity - 1)) == SUCCESS && elem == default_al_capacity - 1);
    assert((errno = array_list_get(al, &elem, default_al_capacity)) == SUCCESS && elem == default_al_capacity);

    // Testing size update
    assert((errno = array_list_delete(al, &elem, al->size - 1)) == SUCCESS && elem == default_al_capacity);
    assert(al->size == default_al_capacity);

    array_list_free(al);

    // Testing downscaling
    al = array_list_new();
    default_al_capacity = al->capacity;

    for (i = 0; i <= default_al_capacity; i++) {
        array_list_append(al, i);
    }

    assert(al->capacity == default_al_capacity * 2);

    for (i = 0; i < default_al_capacity / 2; i++) {
        array_list_delete(al, &elem, al->size - 1);
    }

    assert(al->capacity == default_al_capacity * 2);

    array_list_delete(al, &elem, al->size - 1);

    assert(al->capacity == default_al_capacity);

    array_list_free(al);

    // Testing insert and delete
    al = array_list_new();

    for (i = 0; i < 10; i++) {
        array_list_append(al, i);
    }

    // Can't access out of bounds
    assert(array_list_insert(al, -1, -1) == INDEX_OUT_OF_BOUNDS);
    assert(array_list_insert(al, 10, 10) == INDEX_OUT_OF_BOUNDS);

    // WARNING: the order of the next few operations is important for the unit test
    assert(array_list_insert(al, 9, 9) == SUCCESS);
    assert(array_list_insert(al, 4, 4) == SUCCESS);
    assert(array_list_insert(al, 0, 0) == SUCCESS);

    // Testing print
    array_list_print(al);

    assert(array_list_delete(al, &elem, 12) == SUCCESS && elem == 9);
    assert(array_list_delete(al, &elem, 5) == SUCCESS && elem == 4);
    assert(array_list_delete(al, &elem, 0) == SUCCESS && elem == 0);

    array_list_print(al);

    for (i = 0; i < 10; i++) {
        assert(array_list_get(al, &elem, i) == SUCCESS && elem == i);
    }

    // Testing set
    assert(array_list_set(al, 0, 999) == SUCCESS && array_list_get(al, &elem, 0) == SUCCESS && elem == 999);
    assert(array_list_set(al, 9, 999) == SUCCESS && array_list_get(al, &elem, 9) == SUCCESS && elem == 999);

    // Bounds checking
    assert(array_list_set(al, -1, 999) == INDEX_OUT_OF_BOUNDS);
    assert(array_list_set(al, 10, 999) == INDEX_OUT_OF_BOUNDS);

    // Unit tests for sort-and-search.c (temporary)
    // -------------------------------------------------------------------------

    // Testing linear search
    assert((idx = linear_search(al->array, al->size, 999, 0)) == 0);
    assert(array_list_get(al, &elem, idx) == SUCCESS && elem == 999);

    assert((idx = linear_search(al->array, al->size, 999, 1)) == 9);
    assert(array_list_get(al, &elem, idx) == SUCCESS && elem == 999);

    // Bounds checking
    assert(linear_search(al->array, al->size, 999, -1) == 0);
    assert(linear_search(al->array, al->size, 999, 10) == NOT_FOUND);

    // Testing binary search
    assert((idx = binary_search(al->array, al->size, 0, al->size - 1, 999)) != NOT_FOUND);
    assert(array_list_get(al, &elem, idx) == SUCCESS && elem == 999);

    // Bounds checking
    assert(binary_search(al->array, al->size, 0, al->size, 999) == INDEX_OUT_OF_BOUNDS);
    assert(binary_search(al->array, al->size, -1, al->size - 1, 999) == INDEX_OUT_OF_BOUNDS);

    array_list_free(al);

    return EXIT_SUCCESS;
}
