#include <stdlib.h>
#include "include/array-list.h"
#include "include/mem.h"

array_list array_list_new()
{
    array_list ret = emalloc(sizeof *ret);

    ret->capacity = 4096 / sizeof(int);
    ret->size = 0;
    ret->array = emalloc(ret->capacity * sizeof ret->array[0]);

    return ret;
}

void array_list_free(array_list al)
{
    free(al->array);
    free(al);
}
