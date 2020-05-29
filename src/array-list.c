#include <stdlib.h>
#include <stdio.h>
#include "include/array-list.h"
#include "include/common.h"
#include "include/defs.h"
#include "include/mem.h"
#include "include/quicksort.h"
#include "include/simple-algorithms.h"

/*
Note that array_list_get and array_list_delete return a status code.
To retrieve the value of the element, you need to pass an int pointer into dest.
*/

// Increase the size of the array and if it is full, double its capacity
static void expand(array_list al) {
    if (al->size++ >= al->capacity) {
        al->capacity *= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }
}

// Increase the size of the array and if it is 3/4 empty, half its capacity
static void contract(array_list al) {
    if (--al->size <= al->capacity / 4 && al->capacity / 2 >= (long)(4096 / sizeof(al->array[0]))) {
        al->capacity /= 2;
        al->array = erealloc(al->array, al->capacity * sizeof al->array[0]);
    }
}

// Create a pointer to a new array_list - default capacity is 1024
array_list array_list_new()
{
    array_list ret = emalloc(sizeof *ret);

    ret->capacity = 4096 / sizeof(ret->array[0]);
    ret->size = 0;
    ret->array = emalloc(ret->capacity * sizeof ret->array[0]);

    return ret;
}

// Append an element to the end of an array_list
void array_list_append(array_list al, int elem)
{
    expand(al);
    al->array[al->size - 1] = elem;
}

// Insert an element into an array_list
int array_list_insert(array_list al, int elem, long idx)
{
    int i;

    if (check_bounds(al->size, idx, INSERT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    expand(al);

    // Move any elements greater than the inserted element rightward
    for (i = al->size - 2; i >= idx; i--) {
        al->array[i + 1] = al->array[i];
    }

    al->array[idx] = elem;

    return SUCCESS;
}

// Set an index in an array_list to the value of elem
int array_list_set(array_list al, int elem, long idx)
{
    if (check_bounds(al->size, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    al->array[idx] = elem;
    return SUCCESS;
}

// Delete an element from an array list
int array_list_delete(array_list al, int *dest, long idx)
{
    int i;

    if (check_bounds(al->size, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    *dest = al->array[idx];

    // Move any elements greater than the deleted element leftwards
    for (i = idx; i < al->size - 1; i++) {
        al->array[i] = al->array[i + 1];
    }

    contract(al);

    return SUCCESS;
}

// Get an element from an array_list using an index
int array_list_get(array_list al, int *dest, long idx)
{
    if (check_bounds(al->size, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    *dest = al->array[idx];
    return SUCCESS;
}

// Search an array list for an element and return its index
int array_list_find(array_list al, int elem, long start, int mode)
{
    if (mode == BINARY_SEARCH) {
        return binary_search(al->array, al->size, 0, al->size - 1, elem);
    } else {
        return linear_search(al->array, al->size, elem, start);
    }
}

int array_list_sort(array_list al)
{
    return quicksort(al->array, al->size, 0, al->size - 1);
}

void array_list_reverse(array_list al)
{
    long i, j;
    i = 0;
    j = al->size - 1;

    while (i < j) {
        swap(&al->array[i++], &al->array[j--]);
    }
}

// Show a visual representation of an array_list
void array_list_print(array_list al)
{
    int i;

    for (i = 0; i < al->size; i++) {
        printf("%d\n", al->array[i]);
    }
}

// Free memory associated with an array_list
void array_list_free(array_list al)
{
    free(al->array);
    free(al);
}
