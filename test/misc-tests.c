#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/common.h"
#include "include/mem.h"

int main(int argc, char **argv)
{
    (void)argc;

    int a, b;
    void *ptr;

    // Testing swap
    a = 1;
    b = 2;
    swap(&a, &b);
    assert(a == 2 && b == 1);

    // Testing emalloc and erealloc
    ptr = emalloc(1);
    ptr = erealloc(ptr, 1);
    free(ptr);

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
