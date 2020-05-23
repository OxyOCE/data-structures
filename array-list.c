#include <stdlib.h>
#include "include/array-list.h"
#include "include/mem.h"

static void expand(array_list al) {
    if (al->size >= al->capacity) {
        al->capacity *= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }

    al->size++;
}

static void contract(array_list al) {
    if (al->size <= al->capacity / 4) {
        al->capacity /= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }

    al->size--;
}

array_list array_list_new()
{
    array_list ret = emalloc(sizeof *ret);

    ret->capacity = 4096 / sizeof(ret->array[0]);
    ret->size = 0;
    ret->array = emalloc(ret->capacity * sizeof ret->array[0]);

    return ret;
}

void array_list_append(array_list al, int elem)
{
    expand(al);
    al->array[al->size - 1] = elem;
}

void array_list_insert(array_list al, int elem, long idx)
{
    int i;

    expand(al);

    for (i = al->size - 2; i >= idx; i--) {
        al->array[i + 1] = al->array[i];
    }

    al->array[idx] = elem;

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

    *dest = al->array[al->size - 1];
    contract(al);

    return 0;
}

int array_list_delete(array_list al, int *dest, long idx)
{
    int i;

    if (al->size <= 0) {
        return -1;
    }

    *dest = al->array[idx];

    for (i = idx; i < al->size - 1; i++) {
        al->array[i] = al->array[i + 1];
    }

    contract(al);

    return 0;
}

void array_list_free(array_list al)
{
    free(al->array);
    free(al);
}
