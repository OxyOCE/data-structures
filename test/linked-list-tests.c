#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/linked-list.h"
#include "include/defs.h"

int main(int argc, char **argv)
{
    (void)argc;

    linked_list ll;
    long test_size;
    int i, j, elem;

    ll = linked_list_new();
    test_size = 10;

    // Can't delete from an empty list
    assert(linked_list_delete(ll, &elem, ll->size) == INDEX_OUT_OF_BOUNDS);

    for (i = 0; i < test_size; i++) {
        linked_list_append(ll, i);
    }

    assert(ll->size == test_size);
    linked_list_append(ll, test_size);

    // Testing get
    assert(linked_list_get(ll, &elem, 0) == SUCCESS && elem == 0);
    assert(linked_list_get(ll, &elem, 1) == SUCCESS && elem == 1);
    assert(linked_list_get(ll, &elem, test_size - 1) == SUCCESS && elem == test_size - 1);
    assert(linked_list_get(ll, &elem, test_size) == SUCCESS && elem == test_size);

    // Testing size update
    assert(linked_list_delete(ll, &elem, ll->size - 1) == SUCCESS && elem == test_size);
    assert(ll->size == test_size);

    // Testing reverse
    linked_list_reverse(ll);

    i = 0;
    j = test_size - 1;

    while (i < test_size) {
        linked_list_get(ll, &elem, i++);
        assert(elem == j--);
    }

    linked_list_free(ll);

    // Testing insert and delete
    ll = linked_list_new();

    for (i = 0; i < 10; i++) {
        linked_list_append(ll, i);
    }

    // Bounds checking insert
    assert(linked_list_insert(ll, -1, -1) == INDEX_OUT_OF_BOUNDS);
    assert(linked_list_insert(ll, 11, 11) == INDEX_OUT_OF_BOUNDS);

    // Can use insert as append
    assert(linked_list_insert(ll, 10, 10) == SUCCESS);
    assert(linked_list_delete(ll, &elem, 10) == SUCCESS && elem == 10);

    // WARNING: the order of the next few operations is important for the unit test
    assert(linked_list_insert(ll, 9, 9) == SUCCESS);
    assert(linked_list_insert(ll, 4, 4) == SUCCESS);
    assert(linked_list_insert(ll, 0, 0) == SUCCESS);

    assert(linked_list_delete(ll, &elem, 12) == SUCCESS && elem == 9);
    assert(linked_list_delete(ll, &elem, 5) == SUCCESS && elem == 4);
    assert(linked_list_delete(ll, &elem, 0) == SUCCESS && elem == 0);

    for (i = 0; i < 10; i++) {
        assert(linked_list_get(ll, &elem, i) == SUCCESS && elem == i);
    }

    // Testing set
    assert(linked_list_set(ll, 999, 0) == SUCCESS && linked_list_get(ll, &elem, 0) == SUCCESS && elem == 999);
    assert(linked_list_set(ll, 999, 9) == SUCCESS && linked_list_get(ll, &elem, 9) == SUCCESS && elem == 999);

    // Bounds checking set
    assert(linked_list_set(ll, 999, -1) == INDEX_OUT_OF_BOUNDS);
    assert(linked_list_set(ll, 999, 10) == INDEX_OUT_OF_BOUNDS);

    printf("%s passed\n", argv[0]);

    linked_list_free(ll);

    return EXIT_SUCCESS;
}
