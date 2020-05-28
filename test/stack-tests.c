#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/stack.h"
#include "include/defs.h"

int main(int argc, char **argv)
{
    (void)argc;

    int i, elem;

    stack s = stack_new();

    // Can't pop or peek from an empty stack
    assert(stack_peek(s, &elem) == INDEX_OUT_OF_BOUNDS);
    assert(stack_pop(s, &elem) == INDEX_OUT_OF_BOUNDS);

    // Testing push
    for (i = 0; i < 10; i++) {
        stack_push(s, i);
    }

    // Testing pop and peek
    assert(stack_peek(s, &elem) == SUCCESS && elem == 9);
    assert(stack_pop(s, &elem) == SUCCESS && elem == 9);
    assert(stack_peek(s, &elem) == SUCCESS && elem == 8);

    printf("%s passed\n", argv[0]);

    stack_free(s);

    return EXIT_SUCCESS;
}
