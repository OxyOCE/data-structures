#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

typedef struct array_list
{
    long capacity;
    long size;
    int *array;
} *array_list;

extern array_list array_list_new();
extern void       array_list_append(array_list al, int elem);
extern int        array_list_get(array_list al, int *dest, long idx);
extern void       array_list_free(array_list al);

#endif
