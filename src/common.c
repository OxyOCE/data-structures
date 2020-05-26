#include "include/common.h"

void swap(int *array, long l, long r)
{
    int tmp = array[l];
    array[l] = array[r];
    array[r] = tmp;
}
