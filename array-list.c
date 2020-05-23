#include <stdlib.h>
#include "include/array-list.h"
#include "include/mem.h"

array_list array_list_new()
{
    array_list ret = emalloc(sizeof *ret);

    ret->capacity = 4096 / sizeof(ret->array[0]);
    ret->size = 0;
    ret->array = emalloc(ret->capacity * sizeof ret->array[0]);

    return ret;
}

long array_list_size(array_list al)
{
    return al->size;
}

void array_list_append(array_list al, int elem)
{
    if (al->size >= al->capacity) {
        al->capacity *= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }

    al->array[al->size++] = elem;
}

int array_list_get(array_list al, int *dest, long idx)
{
    if (idx >= al->size || idx < 0) {
        return -1;
    }

    *dest = al->array[idx];
    return 0;
}

int array_list_pop(array_list al, int *dest)
{
    if (al->size <= 0) {
        return -1;
    }

    al->size--;
    *dest = al->array[al->size];
    return 0;
}

void array_list_free(array_list al)
{
    free(al->array);
    free(al);
}
