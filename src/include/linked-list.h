#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct linked_list_node
{
    int data;
    struct linked_list_node *prev;
    struct linked_list_node *next;
} *linked_list_node;

typedef struct linked_list
{
    linked_list_node head;
    linked_list_node tail;
    long size;
} *linked_list;

extern linked_list linked_list_new();
extern void        linked_list_append(linked_list ll, int elem);
extern int         linked_list_insert(linked_list ll, int elem, long idx);
extern int         linked_list_set(linked_list ll, int elem, long idx);
extern int         linked_list_delete(linked_list ll, int *dest, long idx);
extern int         linked_list_get(linked_list ll, int *dest, long idx);
extern int         linked_list_find(linked_list ll, int elem, long start, int mode);
extern void        linked_list_sort(linked_list ll);
extern void        linked_list_reverse(linked_list ll);
extern void        linked_list_print(linked_list ll);
extern void        linked_list_free(linked_list ll);

#endif
