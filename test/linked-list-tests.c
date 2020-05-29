#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/linked-list.h"
#include "include/defs.h"

static int magic_elem = 111;

int main(int argc, char **argv)
{
    (void)argc;

    linked_list ll;
    long i, j;
    int elem;

    // Testing append
    ll = linked_list_new();

    linked_list_append(ll, magic_elem);
    assert(linked_list_get(ll, &elem, 0) == SUCCESS && elem == magic_elem++ && ll->size == 1);
    linked_list_append(ll, magic_elem);
    assert(linked_list_get(ll, &elem, 1) == SUCCESS && elem == magic_elem++ && ll->size == 2);

    linked_list_free(ll);

    // Testing insert
    ll = linked_list_new();

    assert(linked_list_insert(ll, magic_elem++, -1) == INDEX_OUT_OF_BOUNDS && ll->size == 0);
    assert(linked_list_insert(ll, magic_elem++, 1) == INDEX_OUT_OF_BOUNDS && ll->size == 0);

    assert(linked_list_insert(ll, magic_elem, 0) == SUCCESS);
    assert(linked_list_get(ll, &elem, 0) == SUCCESS && elem == magic_elem++ && ll->size == 1);
    assert(linked_list_insert(ll, magic_elem, 0) == SUCCESS);
    assert(linked_list_get(ll, &elem, 0) == SUCCESS && elem == magic_elem++ && ll->size == 2);
    assert(linked_list_insert(ll, magic_elem, 1) == SUCCESS);
    assert(linked_list_get(ll, &elem, 1) == SUCCESS && elem == magic_elem++ && ll->size == 3);
    assert(linked_list_insert(ll, magic_elem, 3) == SUCCESS);
    assert(linked_list_get(ll, &elem, 3) == SUCCESS && elem == magic_elem++ && ll->size == 4);

    linked_list_free(ll);

    // Testing delete
    ll = linked_list_new();

    assert(linked_list_delete(ll, &elem, -1) == INDEX_OUT_OF_BOUNDS && ll->size == 0);
    assert(linked_list_delete(ll, &elem, 0) == INDEX_OUT_OF_BOUNDS && ll->size == 0);
    assert(linked_list_delete(ll, &elem, 1) == INDEX_OUT_OF_BOUNDS && ll->size == 0);

    linked_list_append(ll, magic_elem);
    assert(linked_list_delete(ll, &elem, 0) == SUCCESS && elem == magic_elem++ && ll->size == 0);

    linked_list_append(ll, 999);
    linked_list_append(ll, 998);
    linked_list_append(ll, 997);
    linked_list_append(ll, 996);

    assert(linked_list_delete(ll, &elem, 1) == SUCCESS && elem == 998 && ll->size == 3);
    assert(linked_list_delete(ll, &elem, 2) == SUCCESS && elem == 996 && ll->size == 2);
    assert(linked_list_delete(ll, &elem, 0) == SUCCESS && elem == 999 && ll->size == 1);

    linked_list_free(ll);

    // Testing set and get
    ll = linked_list_new();

    assert(linked_list_set(ll, 0, -1) == INDEX_OUT_OF_BOUNDS && ll->size == 0);
    assert(linked_list_set(ll, 0, 0) == INDEX_OUT_OF_BOUNDS && ll->size == 0);
    assert(linked_list_set(ll, 0, 1) == INDEX_OUT_OF_BOUNDS && ll->size == 0);

    assert(linked_list_get(ll, &elem, -1) == INDEX_OUT_OF_BOUNDS);
    assert(linked_list_get(ll, &elem, 0) == INDEX_OUT_OF_BOUNDS);
    assert(linked_list_get(ll, &elem, 1) == INDEX_OUT_OF_BOUNDS);

    linked_list_append(ll, 0);
    linked_list_append(ll, 0);
    linked_list_append(ll, 0);

    assert(linked_list_set(ll, magic_elem, 0) == SUCCESS && ll->size == 3);
    assert(linked_list_get(ll, &elem, 0) == SUCCESS && elem == magic_elem++);
    assert(linked_list_set(ll, magic_elem, 1) == SUCCESS && ll->size == 3);
    assert(linked_list_get(ll, &elem, 1) == SUCCESS && elem == magic_elem++);
    assert(linked_list_set(ll, magic_elem, 2) == SUCCESS && ll->size == 3);
    assert(linked_list_get(ll, &elem, 2) == SUCCESS && elem == magic_elem++);

    linked_list_free(ll);

    // Testing reverse
    ll = linked_list_new();

    for (i = 0; i < 10; i++) {
        linked_list_append(ll, i);
    }

    linked_list_reverse(ll);

    i = 0;
    j = ll->size - 1;

    while (i < ll->size) {
        assert(linked_list_get(ll, &elem, i++) == SUCCESS && elem == j--);
    }

    linked_list_free(ll);

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
