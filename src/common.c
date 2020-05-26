#include "include/common.h"

void swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}
