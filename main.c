#include <stdlib.h>
#include "include/mem.h"
#include "include/array-list.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    void *ptr = emalloc(1);
    ptr = erealloc(ptr, 1);
    free(ptr);

    array_list al = array_list_new();
    array_list_free(al);

    return EXIT_SUCCESS;
}
