#ifndef STACK_H_
#define STACK_H_

#include "array-list.h"

typedef array_list stack;

extern stack stack_new();
extern void  stack_push(stack s, int elem);
extern int   stack_pop(stack s, int *dest);
extern int   stack_peek(stack s, int *dest);
extern void  stack_print(stack s);
extern void  stack_free(stack s);

#endif
