#include <stdlib.h>
#include <assert.h>
#include "include/mem.h"
#include "include/array-list.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    long default_al_capacity;
    int i;

    // Unit tests for mem.c
    void *ptr = emalloc(1);
    ptr = erealloc(ptr, 1);
    free(ptr);

    // Unit tests for array-list.c
    array_list al = array_list_new();
    default_al_capacity = 4096 / sizeof(al->array[0]);

    assert(al->capacity == default_al_capacity);
    assert(al->size == 0);

    for (i = 0; i < default_al_capacity; i++) {
        array_list_append(al, i);
    }

    assert(al->capacity == default_al_capacity);
    assert(al->size == default_al_capacity);

    array_list_append(al, default_al_capacity);
    array_list_append(al, default_al_capacity + 1);

    assert(al->capacity == default_al_capacity * 2);
    assert(al->size == default_al_capacity + 2);

    assert(al->array[0] == 0);
    assert(al->array[1] == 1);
    assert(al->array[2] == 2);
    assert(al->array[default_al_capacity - 1] == default_al_capacity - 1);
    assert(al->array[default_al_capacity] == default_al_capacity);
    assert(al->array[default_al_capacity + 1] == default_al_capacity + 1);

    array_list_free(al);

    return EXIT_SUCCESS;
}
