#include "include/common.h"
#include "include/defs.h"

// Swaps the value of two integer pointers
void swap(int *l, int *r)
{
    int tmp = *l;
    *l = *r;
    *r = tmp;
}

// Check that the index is not out of bounds
int check_bounds(long size, long idx, int mode)
{
    // Most applicable operations require the list to be non-empty
    if (mode == DEFAULT) {
        if (idx >= size || idx < 0 || size <= 0) {
            return INDEX_OUT_OF_BOUNDS;
        }
    }

    // Insert can operate on an empty list
    if (mode == INSERT) {
        if (idx > size || idx < 0) {
            return INDEX_OUT_OF_BOUNDS;
        }
    }

    return SUCCESS;
}
