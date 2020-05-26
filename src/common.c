#include "include/common.h"

void swap(long *l, long *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}
