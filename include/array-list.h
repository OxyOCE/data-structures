#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#define NOT_FOUND -1
#define SUCCESS 0
#define INDEX_OUT_OF_BOUNDS 1
#define DEFAULT 2
#define INSERT 3

typedef struct array_list
{
    long capacity;
    long size;
    int *array;
} *array_list;

extern array_list array_list_new();
extern void       array_list_append(array_list al, int elem);
extern int        array_list_insert(array_list al, int elem, long idx);
extern int        array_list_get(array_list al, int *dest, long idx);
extern int        array_list_linear_search(array_list al, int elem, long start);
extern int        array_list_set(array_list al, long idx, int elem);
extern int        array_list_delete(array_list al, int *dest, long idx);
extern void       array_list_print(array_list al);
extern void       array_list_free(array_list al);

#endif
