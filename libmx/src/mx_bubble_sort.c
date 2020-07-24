#include "libmx.h"

/**
 * @brief sorts an array of strings in place in lexicographical order uses the bubble sort algorithm
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/5/2020
 * @returns Returns the number of swap operations
 */
int mx_bubble_sort(char **arr, int size) {
    int swaps = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {

            int compr_result = mx_strcmp(arr[i], arr[j]);

            if (compr_result > 0) {
                swaps++;

                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }
    }
    return swaps;
}
