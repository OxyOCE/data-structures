#include <stdlib.h>
#include <stdio.h>
#include "include/linked-list.h"
#include "include/defs.h"
#include "include/mem.h"
#include "include/mergesort.h"

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
    linked_list_node new_node = emalloc(sizeof *new_node);
    new_node->data = elem;

    if (ll->tail == NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
        ll->head = new_node;
    } else {
        new_node->prev = ll->tail;
        new_node->next = NULL;
        ll->tail->next = new_node;
    }

    ll->tail = new_node;
    ll->size++;
}

int linked_list_insert(linked_list ll, int elem, long idx)
{
    linked_list_node curr_node, new_node;
    long curr_node_idx;

    if (check_bounds(ll->size, idx, INSERT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    if (ll->tail == NULL) {
        linked_list_append(ll, elem);
        return SUCCESS;
    }

    curr_node = ll->head;
    curr_node_idx = 0;
    while (curr_node->next != NULL && curr_node_idx < idx) {
        curr_node = curr_node->next;
        curr_node_idx++;
    }

    if (curr_node->next == NULL && curr_node_idx < idx) {
        linked_list_append(ll, elem);
        return SUCCESS;
    }

    new_node = emalloc(sizeof *new_node);
    new_node->data = elem;

    if (curr_node->prev == NULL) {
        ll->head = new_node;
        new_node->prev = NULL;
    } else {
        new_node->prev = curr_node->prev;
        curr_node->prev->next = new_node;
    }
    new_node->next = curr_node;
    curr_node->prev = new_node;
    ll->size++;

    return SUCCESS;
}

int linked_list_set(linked_list ll, int elem, long idx)
{
    linked_list_node curr_node;
    long curr_node_idx;

    if (check_bounds(ll->size, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    curr_node = ll->head;
    curr_node_idx = 0;
    while (curr_node->next != NULL && curr_node_idx++ < idx) {
        curr_node = curr_node->next;
    }

    if (curr_node_idx < idx) {
        return INDEX_OUT_OF_BOUNDS;
    }

    curr_node->data = elem;

    return SUCCESS;
}

int linked_list_delete(linked_list ll, int *dest, long idx)
{
    linked_list_node curr_node, new_node;
    long curr_node_idx;

    if (check_bounds(ll->size, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS || ll->head == NULL) {
        return INDEX_OUT_OF_BOUNDS;
    }

    curr_node = ll->head;
    curr_node_idx = 0;
    while (curr_node->next != NULL && curr_node_idx++ < idx) {
        curr_node = curr_node->next;
    }

    if (curr_node_idx < idx) {
        return INDEX_OUT_OF_BOUNDS;
    }

    if (curr_node->prev == NULL) {
        ll->head = curr_node->next;
        curr_node->next->prev = NULL;
    } else if (curr_node->next == NULL) {
        ll->tail = curr_node->prev;
        curr_node->prev->next = NULL;
    } else {
        curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;
    }

    *dest = curr_node->data;
    ll->size--;
    free(curr_node);

    return SUCCESS;
}

int linked_list_get(linked_list ll, int *dest, long idx)
{
    linked_list_node curr_node;
    long curr_node_idx;

    if (check_bounds(ll->size, idx, DEFAULT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    curr_node = ll->head;
    curr_node_idx = 0;
    while (curr_node->next != NULL && curr_node_idx++ < idx) {
        curr_node = curr_node->next;
    }

    if (curr_node_idx < idx) {
        return INDEX_OUT_OF_BOUNDS;
    }

    *dest = curr_node->data;

    return SUCCESS;
}

int linked_list_find(linked_list ll, int elem, long start, int mode)
{

}

void linked_list_sort(linked_list ll)
{
    msort_ll(ll);
}

void linked_list_reverse(linked_list ll)
{
    linked_list_node temp, curr_node = ll->head;

    temp = ll->head;
    ll->head = ll->tail;
    ll->tail = temp;

    while (curr_node != NULL) {
        temp = curr_node->next;
        curr_node->next = curr_node->prev;
        curr_node->prev = temp;
        curr_node = curr_node->prev;
    }
}

void linked_list_print(linked_list ll)
{
    linked_list_node curr_node = ll->head;

    do {
        printf("%d\n", curr_node->data);
    } while ((curr_node = curr_node->next) != NULL);
}

void linked_list_free(linked_list ll)
{
    linked_list_node curr_node, temp_node;
    curr_node = ll->head;

    if (curr_node != NULL) {
        temp_node = curr_node->next;

        while (temp_node != NULL) {
            free(curr_node);
            curr_node = temp_node;
            temp_node = temp_node->next;
        }

        free(curr_node);
    }

    free(ll);
}
