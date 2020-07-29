#include "libmx.h"

static void comparator(char **arr, int pivot, int *l, int *r) {
    for (; mx_strlen(arr[*l]) < pivot; ++*l);
    for (; mx_strlen(arr[*r]) > pivot; --*r);
}

static void quick_sort(char **arr, int *l, int *r, int *count) {
    if (*l <= *r) {
        if ((*l != *r) && (mx_strlen(arr[*l]) != mx_strlen(arr[*r]))) {
            str_swap(&arr[*l], &arr[*r]);
            ++*count;
        }
        ++*l;
        --*r;
    }
}

/**
 * QuickSort Implementation
 * @param arr array of strings
 * @param low low
 * @param high high
 * @return count of swaps
 */
int mx_quicksort(char **arr, int left, int right) {
    int pivot;
    int l = left;
    int r = right;
    int count = 0;

    if (!arr)
        return -1;
    pivot = mx_strlen(arr[(left + (right - left) / 2)]);
    while (l <= r) {
        comparator(arr, pivot, &l, &r);
        quick_sort(arr, &l, &r, &count);
    }
    if (left < r)
        count += mx_quicksort(arr, left, r);
    if (l < right)
        count += mx_quicksort(arr, l, right);
    return count;
}
