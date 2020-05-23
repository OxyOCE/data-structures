#include <stdlib.h>
#include "include/mem.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    void *ptr = emalloc(1);
    ptr = erealloc(ptr, 1);
    free(ptr);

    return EXIT_SUCCESS;
}
