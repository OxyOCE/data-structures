#include "include/common.h"

// Swaps the value of two integer pointers
void swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}
