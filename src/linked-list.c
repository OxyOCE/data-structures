#include <stdlib.h>
#include <stdio.h>
#include "include/linked-list.h"
#include "include/common.h"
#include "include/defs.h"
#include "include/mem.h"
#include "include/mergesort.h"
#include "include/simple-algorithms.h"

// Create a pointer to a new linked_list
linked_list linked_list_new()
{
    linked_list ret = emalloc(sizeof *ret);

    ret->head = NULL;
    ret->tail = NULL;
    ret->size = 0;

    return ret;
}

// Append an element to the end of a linked_list
void linked_list_append(linked_list ll, int elem)
{
    linked_list_node new_node = emalloc(sizeof *new_node);
    new_node->data = elem;

    // If the list is empty, prev is null and update the head
    if (ll->tail == NULL) {
        new_node->prev = NULL;
        ll->head = new_node;
    } else { // Else prev is the old tail and old tail next is new_node
        new_node->prev = ll->tail;
        ll->tail->next = new_node;
    }

    // New tail next is null
    new_node->next = NULL;
    // New node is new tail
    ll->tail = new_node;
    ll->size++;
}

// Insert an element into a linked_list
int linked_list_insert(linked_list ll, int elem, long idx)
{
    linked_list_node curr_node, new_node;
    long curr_node_idx;

    if (check_bounds(ll->size, idx, INSERT) == INDEX_OUT_OF_BOUNDS) {
        return INDEX_OUT_OF_BOUNDS;
    }

    // If empty list, append
    if (ll->tail == NULL) {
        linked_list_append(ll, elem);
        return SUCCESS;
    }

    // Find where to insert
    curr_node = ll->head;
    curr_node_idx = 0;
    while (curr_node->next != NULL && curr_node_idx < idx) {
        curr_node = curr_node->next;
        curr_node_idx++;
    }

    // If index is past the end (by 1 only), append
    if (curr_node->next == NULL && curr_node_idx < idx) {
        linked_list_append(ll, elem);
        return SUCCESS;
    }

    new_node = emalloc(sizeof *new_node);
    new_node->data = elem;

    // If index is head of list, update head
    if (curr_node->prev == NULL) {
        ll->head = new_node;
        new_node->prev = NULL;
    } else { // Else update links to and from previous node
        new_node->prev = curr_node->prev;
        curr_node->prev->next = new_node;
    }
    // Update links to and from next node
    new_node->next = curr_node;
    curr_node->prev = new_node;
    ll->size++;

    return SUCCESS;
}

// Set an index in a linked_list to the value of elem
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

// Delete an element from a linked_list
int linked_list_delete(linked_list ll, int *dest, long idx)
{
    linked_list_node curr_node;
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

    // If deleting from head
    if (curr_node->prev == NULL) {
        // New head is next node
        ll->head = curr_node->next;
        // If new head is not null (list size > 0), new head's prev is null
        if (curr_node->next != NULL) {
            curr_node->next->prev = NULL;
        }
    }
    // If deleting from tail
    if (curr_node->next == NULL) {
        // New tail is prev node
        ll->tail = curr_node->prev;
        // If new tail is not null (list size > 0), new tail's next is null
        if (curr_node->prev != NULL) {
            curr_node->prev->next = NULL;
        }
    }
    // If deleting inside list (neither head nor tail), stitch prev node and next node links together
    if (curr_node->next != NULL && curr_node->prev != NULL) {
        curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;
    }

    *dest = curr_node->data;
    ll->size--;
    free(curr_node);

    return SUCCESS;
}

// Get an element from a linked_list using an index
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

// Search a linked_list for an element and return its index
int linked_list_find(linked_list ll, int elem, long start)
{
    return search_ll(ll, elem, start);
}

// Sort a linked_list using mergesort
void linked_list_sort(linked_list ll)
{
    msort_ll(ll);
}

// Reverse a linked_list
void linked_list_reverse(linked_list ll)
{
    // To reverse a linked list, simply swap the head and the tail and swap all nodes' next and prev pointers
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

// Show a visual representation of a linked_list
void linked_list_print(linked_list ll)
{
    linked_list_node curr_node = ll->head;

    do {
        printf("%d\n", curr_node->data);
    } while ((curr_node = curr_node->next) != NULL);
}

// Free memory associated with a linked_list
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
