#include <stdlib.h>
#include "include/linked-list.h"
#include "include/mem.h"

linked_list linked_list_new()
{
    linked_list ret = emalloc(sizeof *ret);

    ret->head = NULL;
    ret->tail = NULL;
    ret->size = 0;

    return ret;
}

void linked_list_append(linked_list ll, int elem)
{

}

int linked_list_insert(linked_list ll, int elem, long idx)
{

}

int linked_list_set(linked_list ll, int elem, long idx)
{

}

int linked_list_delete(linked_list ll, int *dest, long idx)
{

}

int linked_list_get(linked_list ll, int *dest, long idx)
{

}

int linked_list_find(linked_list ll, int elem, long start, int mode)
{

}

int linked_list_sort(linked_list ll)
{

}

void linked_list_reverse(linked_list ll)
{

}

void linked_list_print(linked_list ll)
{

}

void linked_list_free(linked_list ll)
{

}