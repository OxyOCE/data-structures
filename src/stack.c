#include "include/stack.h"

/*
    A stack is a last in first out abstract data type with three main methods:

    Push - Put an item at the top of the stack
    Pop  - Remove an item from the top of the stack
    Peek - Look at the item on the top of the stack

    An array list is a great data stucture to back a stack
    because push, pop and peek can all be O(1) operations.
*/

stack stack_new()
{
    return array_list_new();
}

void stack_push(stack s, int elem)
{
    // Put an element on the end (on the top)
    array_list_append(s, elem);
}

int stack_pop(stack s, int *dest)
{
    // Delete an element from the end (from the top) and store its value
    return array_list_delete(s, dest, s->size - 1);
}

int stack_peek(stack s, int *dest)
{
    // Look at the element on the end (on the top)
    return array_list_get(s, dest, s->size - 1);
}

void stack_print(stack s)
{
    array_list_print(s);
}

void stack_free(stack s)
{
    array_list_free(s);
}
