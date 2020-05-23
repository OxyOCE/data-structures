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
    void *ptr = emalloc(1);
    ptr = erealloc(ptr, 1);
    free(ptr);

    // Unit tests for array-list.c
    array_list al = array_list_new();
    default_al_capacity = al->capacity;

    assert(al->size == 0);
    assert((errno = array_list_pop(al, &elem)) == -1);

    for (i = 0; i < default_al_capacity; i++) {
        array_list_append(al, i);
    }

    assert(al->capacity == default_al_capacity);
    assert(al->size == default_al_capacity);

    array_list_append(al, default_al_capacity);
    array_list_append(al, default_al_capacity + 1);

    assert(al->capacity == default_al_capacity * 2);
    assert(al->size == default_al_capacity + 2);

    assert((errno = array_list_get(al, &elem, 0)) == 0 && elem == 0);
    assert((errno = array_list_get(al, &elem, 1)) == 0 && elem == 1);
    assert((errno = array_list_get(al, &elem, 2)) == 0 && elem == 2);
    assert((errno = array_list_get(al, &elem, default_al_capacity - 1)) == 0 && elem == default_al_capacity - 1);
    assert((errno = array_list_get(al, &elem, default_al_capacity)) == 0 && elem == default_al_capacity);
    assert((errno = array_list_get(al, &elem, default_al_capacity + 1)) == 0 && elem == default_al_capacity + 1);

    assert((errno = array_list_pop(al, &elem)) == 0 && elem == default_al_capacity + 1);
    assert(al->size == default_al_capacity + 1);


    array_list_free(al);

    return EXIT_SUCCESS;
}
