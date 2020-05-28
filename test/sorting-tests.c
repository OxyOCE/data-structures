#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/heapsort.h"
#include "include/mergesort.h"
#include "include/quicksort.h"
#include "include/simple-algorithms.h"
#include "include/mem.h"

/*
These test suites compare the results of the sorting algorithms against c's qsort routine.
There are 18 different arrays the algorithms are tested across.
*/

// Reference: https://reprog.wordpress.com/2010/05/20/what-does-it-take-to-test-a-sorting-routine/
static int *suite_1[] = {
    (int []) {0},
    (int []) {0, 0},
    (int []) {0, 0, 0},
    (int []) {0, 1},
    (int []) {1, 0},
    (int []) {0, 1, 2},
    (int []) {0, 2, 1},
    (int []) {1, 0, 2},
    (int []) {1, 2, 0},
    (int []) {2, 0, 1},
    (int []) {2, 1, 0},
    (int []) {0, 1, 1},
    (int []) {1, 0, 1},
    (int []) {1, 1, 0}
};

static int *suite_2[] = {
    (int []) {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    (int []) {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    (int []) {42, 9, 17, 54, 602, -3, 54, 999, -11},
    (int []) {-11, -3, 9, 17, 42, 54, 54, 602, 999}
};

static int suite_1_size = 14;
static int suite_2_size = 4;

static int suite_1_sizes[] = {1, 2, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3};
static int suite_2_sizes[] = {10, 10, 9, 9};

static int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

static void run_suite(int *suite[], int suite_size, int suite_sizes[])
{
    int i, j, test_size;
    int *scratch_array_heapsort, *scratch_array_mergesort, *scratch_array_insertion_sort, *scratch_array_quicksort, *scratch_array_qsort;

    for (i = 0; i < suite_size; i++) {
        test_size = suite_sizes[i];
        scratch_array_heapsort = emalloc(test_size * sizeof scratch_array_heapsort[0]);
        scratch_array_mergesort = emalloc(test_size * sizeof scratch_array_mergesort[0]);
        scratch_array_insertion_sort = emalloc(test_size * sizeof scratch_array_insertion_sort[0]);
        scratch_array_quicksort = emalloc(test_size * sizeof scratch_array_quicksort[0]);
        scratch_array_qsort = emalloc(test_size * sizeof scratch_array_qsort[0]);

        for (j = 0; j < test_size; j++) {
            scratch_array_heapsort[j] = suite[i][j];
            scratch_array_mergesort[j] = suite[i][j];
            scratch_array_insertion_sort[j] = suite[i][j];
            scratch_array_quicksort[j] = suite[i][j];
            scratch_array_qsort[j] = suite[i][j];
        }

        heapsort(scratch_array_heapsort, test_size);
        msort(scratch_array_mergesort, test_size, 0, test_size - 1);
        insertion_sort(scratch_array_insertion_sort, test_size);
        quicksort(scratch_array_quicksort, test_size, 0, test_size - 1);
        qsort(scratch_array_qsort, test_size, sizeof scratch_array_qsort[0], compare);

        for (j = 0; j < test_size; j++)
        {
            assert(scratch_array_heapsort[j] == scratch_array_qsort[j]);
            assert(scratch_array_mergesort[j] == scratch_array_qsort[j]);
            assert(scratch_array_insertion_sort[j] == scratch_array_qsort[j]);
            assert(scratch_array_quicksort[j] == scratch_array_qsort[j]);
        }

        free(scratch_array_heapsort);
        free(scratch_array_mergesort);
        free(scratch_array_insertion_sort);
        free(scratch_array_quicksort);
        free(scratch_array_qsort);
    }
}

int main(int argc, char **argv)
{
    (void)argc;

    run_suite(suite_1, suite_1_size, suite_1_sizes);
    run_suite(suite_2, suite_2_size, suite_2_sizes);

    printf("%s passed\n", argv[0]);

    return EXIT_SUCCESS;
}
