#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/queue.h"
#include "include/defs.h"

int main(int argc, char **argv)
{
    (void)argc;

    int i, elem;

    queue q = queue_new();

    // Can't dequeue from an empty queue
    assert(dequeue(q, &elem) == INDEX_OUT_OF_BOUNDS);

    // Testing enqueue
    for (i = 0; i < 10; i++) {
        enqueue(q, i);
    }

    assert(q->size == 10);

    // Testing dequeue
    for (i = 0; i < 10; i++) {
        assert(dequeue(q, &elem) == SUCCESS && elem == i);
    }

    assert(q->size == 0);

    printf("%s passed\n", argv[0]);

    queue_free(q);

    return EXIT_SUCCESS;
}
