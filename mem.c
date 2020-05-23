#include "include/mem.h"

void *emalloc(size_t s)
{
    void *ptr = malloc(s);

    if (NULL == ptr) {
        fprintf(stderr, "Fatal: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

void *erealloc(void *ptr, size_t s)
{
    void *new_ptr = realloc(ptr, s);

    if (NULL == new_ptr) {
        fprintf(stderr, "Fatal: realloc failed\n");
        exit(EXIT_FAILURE);
    }

    return new_ptr;
}
