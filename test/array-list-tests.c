#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/array-list.h"
#include "include/defs.h"

int main(int argc, char **argv)
{
    (void)argc;

    array_list al;
    long default_al_capacity;
    int i, j, elem;

    al = array_list_new();
    default_al_capacity = al->capacity;

    // Can't delete from an empty list
    assert(array_list_delete(al, &elem, al->size) == INDEX_OUT_OF_BOUNDS);

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
    assert(array_list_get(al, &elem, 0) == SUCCESS && elem == 0);
    assert(array_list_get(al, &elem, 1) == SUCCESS && elem == 1);
    assert(array_list_get(al, &elem, default_al_capacity - 1) == SUCCESS && elem == default_al_capacity - 1);
    assert(array_list_get(al, &elem, default_al_capacity) == SUCCESS && elem == default_al_capacity);

    // Testing size update
    assert(array_list_delete(al, &elem, al->size - 1) == SUCCESS && elem == default_al_capacity);
    assert(al->size == default_al_capacity);

    // Testing reverse
    array_list_reverse(al);

    i = 0;
    j = default_al_capacity - 1;

    while (i < default_al_capacity) {
        assert(al->array[i++] == j--);
    }

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

    // Bounds checking insert
    assert(array_list_insert(al, -1, -1) == INDEX_OUT_OF_BOUNDS);
    assert(array_list_insert(al, 10, 10) == INDEX_OUT_OF_BOUNDS);

    // WARNING: the order of the next few operations is important for the unit test
    assert(array_list_insert(al, 9, 9) == SUCCESS);
    assert(array_list_insert(al, 4, 4) == SUCCESS);
    assert(array_list_insert(al, 0, 0) == SUCCESS);

    assert(array_list_delete(al, &elem, 12) == SUCCESS && elem == 9);
    assert(array_list_delete(al, &elem, 5) == SUCCESS && elem == 4);
    assert(array_list_delete(al, &elem, 0) == SUCCESS && elem == 0);

    for (i = 0; i < 10; i++) {
        assert(array_list_get(al, &elem, i) == SUCCESS && elem == i);
    }

    // Testing set
    assert(array_list_set(al, 999, 0) == SUCCESS && array_list_get(al, &elem, 0) == SUCCESS && elem == 999);
    assert(array_list_set(al, 999, 9) == SUCCESS && array_list_get(al, &elem, 9) == SUCCESS && elem == 999);

    // Bounds checking set
    assert(array_list_set(al, 999, -1) == INDEX_OUT_OF_BOUNDS);
    assert(array_list_set(al, 999, 10) == INDEX_OUT_OF_BOUNDS);

    printf("%s passed\n", argv[0]);

    array_list_free(al);

    return EXIT_SUCCESS;
}
