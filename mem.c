#include <stdlib.h>
#include <stdio.h>
#include "include/mem.h"

void *emalloc(size_t s)
{
    void *ret = malloc(s);

    if (NULL == ret) {
        fprintf(stderr, "Fatal: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    return ret;
}

void *erealloc(void *ptr, size_t s)
{
    void *ret = realloc(ptr, s);

    if (NULL == ret) {
        fprintf(stderr, "Fatal: realloc failed\n");
        exit(EXIT_FAILURE);
    }

    return ret;
}
