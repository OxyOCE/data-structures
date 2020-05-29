#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/array-list.h"
#include "include/defs.h"

static int magic_elem = 111;

int main(int argc, char **argv)
{
    (void)argc;

    array_list al;
    long expected_capacity, i, j;
    int elem;

    // Testing append
    al = array_list_new();

    array_list_append(al, magic_elem);
    assert(al->array[0] == magic_elem++ && al->size == 1);
    array_list_append(al, magic_elem);
    assert(al->array[1] == magic_elem++ && al->size == 2);

    array_list_free(al);

    // Testing insert
    al = array_list_new();

    assert(array_list_insert(al, magic_elem++, -1) == INDEX_OUT_OF_BOUNDS && al->size == 0);
    assert(array_list_insert(al, magic_elem++, 1) == INDEX_OUT_OF_BOUNDS && al->size == 0);

    assert(array_list_insert(al, magic_elem, 0) == SUCCESS);
    assert(al->array[0] == magic_elem++ && al->size == 1);
    assert(array_list_insert(al, magic_elem, 0) == SUCCESS);
    assert(al->array[0] == magic_elem++ && al->size == 2);
    assert(array_list_insert(al, magic_elem, 1) == SUCCESS);
    assert(al->array[1] == magic_elem++ && al->size == 3);
    assert(array_list_insert(al, magic_elem, 3) == SUCCESS);
    assert(al->array[3] == magic_elem++ && al->size == 4);

    array_list_free(al);

    // Testing delete
    al = array_list_new();

    assert(array_list_delete(al, &elem, -1) == INDEX_OUT_OF_BOUNDS && al->size == 0);
    assert(array_list_delete(al, &elem, 0) == INDEX_OUT_OF_BOUNDS && al->size == 0);
    assert(array_list_delete(al, &elem, 1) == INDEX_OUT_OF_BOUNDS && al->size == 0);

    array_list_append(al, magic_elem);
    assert(array_list_delete(al, &elem, 0) == SUCCESS && elem == magic_elem++ && al->size == 0);

    array_list_append(al, 999);
    array_list_append(al, 998);
    array_list_append(al, 997);
    array_list_append(al, 996);

    assert(array_list_delete(al, &elem, 1) == SUCCESS && elem == 998 && al->size == 3);
    assert(array_list_delete(al, &elem, 2) == SUCCESS && elem == 996 && al->size == 2);
    assert(array_list_delete(al, &elem, 0) == SUCCESS && elem == 999 && al->size == 1);

    array_list_free(al);

    // Testing set and get
    al = array_list_new();

    assert(array_list_set(al, 0, -1) == INDEX_OUT_OF_BOUNDS && al->size == 0);
    assert(array_list_set(al, 0, 0) == INDEX_OUT_OF_BOUNDS && al->size == 0);
    assert(array_list_set(al, 0, 1) == INDEX_OUT_OF_BOUNDS && al->size == 0);

    assert(array_list_get(al, &elem, -1) == INDEX_OUT_OF_BOUNDS);
    assert(array_list_get(al, &elem, 0) == INDEX_OUT_OF_BOUNDS);
    assert(array_list_get(al, &elem, 1) == INDEX_OUT_OF_BOUNDS);

    array_list_append(al, 0);
    array_list_append(al, 0);
    array_list_append(al, 0);

    assert(array_list_set(al, magic_elem, 0) == SUCCESS && al->size == 3);
    assert(array_list_get(al, &elem, 0) == SUCCESS && elem == magic_elem++);
    assert(array_list_set(al, magic_elem, 1) == SUCCESS && al->size == 3);
    assert(array_list_get(al, &elem, 1) == SUCCESS && elem == magic_elem++);
    assert(array_list_set(al, magic_elem, 2) == SUCCESS && al->size == 3);
    assert(array_list_get(al, &elem, 2) == SUCCESS && elem == magic_elem++);

    array_list_free(al);

    // Testing reverse
    al = array_list_new();
    expected_capacity = al->capacity;

    for (i = 0; i < expected_capacity; i++) {
        array_list_append(al, i);
    }

    array_list_reverse(al);

    i = 0;
    j = al->size - 1;

    while (i < al->size) {
        assert(al->array[i++] == j--);
    }

    array_list_free(al);

    // Testing scaling
    al = array_list_new();

    for (i = 0; i < expected_capacity; i++) {
        array_list_append(al, i);
    }

    assert(al->capacity == expected_capacity);
    array_list_append(al, ++i);
    assert(al->capacity == expected_capacity * 2);

    for (i = 0; i < expected_capacity / 2 + 1; i++) {
        array_list_delete(al, &elem, al->size - 1);
    }

    assert(al->capacity == expected_capacity);
    array_list_free(al);

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
