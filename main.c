#include <stdlib.h>
#include <assert.h>
#include "include/mem.h"
#include "include/array-list.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    long default_al_capacity;
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
    assert((errno = array_list_delete(al, &elem, al->size)) == -1);

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
    assert((errno = array_list_get(al, &elem, 0)) == 0 && elem == 0);
    assert((errno = array_list_get(al, &elem, 1)) == 0 && elem == 1);
    assert((errno = array_list_get(al, &elem, default_al_capacity - 1)) == 0 && elem == default_al_capacity - 1);
    assert((errno = array_list_get(al, &elem, default_al_capacity)) == 0 && elem == default_al_capacity);

    // Testing size update
    assert((errno = array_list_delete(al, &elem, al->size - 1)) == 0 && elem == default_al_capacity);
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
    assert(array_list_insert(al, -1, -1) == -1);
    assert(array_list_insert(al, 10, 10) == -1);

    // WARNING: the order of the next few operations is important for the unit test
    assert(array_list_insert(al, 9, 9) == 0);
    assert(array_list_insert(al, 4, 4) == 0);
    assert(array_list_insert(al, 0, 0) == 0);

    // Testing print
    array_list_print(al);

    assert(array_list_delete(al, &elem, 12) == 0 && elem == 9);
    assert(array_list_delete(al, &elem, 5) == 0 && elem == 4);
    assert(array_list_delete(al, &elem, 0) == 0 && elem == 0);

    array_list_print(al);

    for (i = 0; i < 10; i++) {
        assert(array_list_get(al, &elem, i) == 0 && elem == i);
    }

    array_list_free(al);

    return EXIT_SUCCESS;
}
