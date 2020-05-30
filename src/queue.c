#include "include/queue.h"

/*
    A queue is a first in first out abstract data type with two main methods:

    Enqueue - Add an element to the back of a queue
    Dequeue - Remove and store an element from the front of a queue

    A linked list is a great data stucture to back a queue
    because both operations are O(1).
*/

queue queue_new()
{
    return linked_list_new();
}

// Add an element to the back of a queue
void enqueue(queue q, int elem)
{
    linked_list_append(q, elem);
}

// Remove and store an element from the front of a queue
int dequeue(queue q, int *dest)
{
    return linked_list_delete(q, dest, 0);
}

void queue_print(queue q)
{
    linked_list_print(q);
}

void queue_free(queue q)
{
    linked_list_free(q);
}
