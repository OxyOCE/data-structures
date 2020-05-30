#ifndef QUEUE_H_
#define QUEUE_H_

#include "linked-list.h"

typedef linked_list queue;

extern queue queue_new();
extern void  enqueue(queue q, int elem);
extern int   dequeue(queue q, int *dest);
extern void  queue_print(queue q);
extern void  queue_free(queue q);

#endif
