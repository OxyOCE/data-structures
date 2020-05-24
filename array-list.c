#include <stdlib.h>
#include <stdio.h>
#include "include/array-list.h"
#include "include/mem.h"

static void expand(array_list al) {
    if (al->size++ >= al->capacity) {
        al->capacity *= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }
}

static void contract(array_list al) {
    if (--al->size <= al->capacity / 4 && al->capacity / 2 >= (long)(4096 / sizeof(al->array[0]))) {
        al->capacity /= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }
}

static int check_bounds(array_list al, long idx, int mode)
{
    if (mode == DEFAULT) {
        if (idx >= al->size || idx < 0 || al->size <= 0) {
            return INDEX_OUT_OF_BOUNDS;
        }
    }

    if (mode == INSERT) {
        if (idx >= al->size || idx < 0) {
            return INDEX_OUT_OF_BOUNDS;
        }
    }

    return SUCCESS;
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

int array_list_insert(array_list al, int elem, long idx)
{
    int i;

    if (check_bounds(al, idx, INSERT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    expand(al);

    for (i = al->size - 2; i >= idx; i--) {
        al->array[i + 1] = al->array[i];
    }

    al->array[idx] = elem;

    return SUCCESS;

}

int array_list_get(array_list al, int *dest, long idx)
{
    if (check_bounds(al, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    *dest = al->array[idx];
    return SUCCESS;
}

int array_list_linear_search(array_list al, int elem, long start)
{
    int i;

    if (start < 0) {
        i = 0;
    } else {
        i = start;
    }

    for (; i < al->size; i++) {
        if (al->array[i] == elem) {
            return i;
        }
    }

    return NOT_FOUND;
}

int array_list_set(array_list al, long idx, int elem)
{
    if (check_bounds(al, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    al->array[idx] = elem;
    return SUCCESS;
}

int array_list_delete(array_list al, int *dest, long idx)
{
    int i;

    if (check_bounds(al, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    *dest = al->array[idx];

    for (i = idx; i < al->size - 1; i++) {
        al->array[i] = al->array[i + 1];
    }

    contract(al);

    return SUCCESS;
}

void array_list_print(array_list al)
{
    int i;

    for (i = 0; i < al->size; i++) {
        printf("%d\n", al->array[i]);
    }
}

void array_list_free(array_list al)
{
    free(al->array);
    free(al);
}
