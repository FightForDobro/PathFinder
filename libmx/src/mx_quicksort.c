#include "libmx.h"

static void logic(char **arr, int *i, int *j, char *pivot, int *swaps) {
    while (*i <= *j) {

        while (mx_strlen(arr[*i]) - mx_strlen(pivot) < 0)
            *i += 1;

        while (mx_strlen(arr[*j]) - mx_strlen(pivot) > 0)
            *j -= 1;

        if (*i <= *j) {
            str_swap(&arr[*i], &arr[*j], swaps);
            *i += 1;
            *j -= 1;
        }
    }
}

/**
 * QuickSort Implementation
 * @param arr array of strings
 * @param low low
 * @param high high
 * @return count of swaps
 */
int mx_quicksort(char **arr, int low, int high) {

    if (arr == NULL || *arr == NULL) return -1;
    if (low >= high) return 0;

    int swaps = 0;

    int middle = low + (high - low) / 2;
    char *pivot = arr[middle];

    int i = low;
    int j = high;

    logic(arr, &i, &j, pivot, &swaps);

    if (low < j)
        swaps += mx_quicksort(arr, low, j);

    if (high > i)
        swaps += mx_quicksort(arr, i, high);

    return swaps;
}
