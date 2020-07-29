#include "libmx.h"

/**
 * @brief Searches the strings  in the array arr with the given sizeof array
 * uses the binary search algorithm assuming that the input array has already been sorted in a lexicographical order
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/5/2020
 * @returns returns the index of the found string in the array
 *  returns-1  in case of errors or if the string has not been found
 *  assigns the number of required iterations to the count pointer
 * @example arr= {"222", "Abcd", "aBc", "ab", "az", "z"}; count = 0;
 * mx_binary_search(arr, 6, "ab", &count); //returns 3 and count = 3 count = 0;
 * mx_binary_search(arr, 6, "aBc", &count); //returns 2 and count = 1 count = 0;
 * mx_binary_search(arr, 6, "aBz", &count); //returns -1 and count = 0
 */
int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0, mid, high = size - 1;
    int c = 0;
    while (low <= high) {
        c++;

        mid = (low + high) / 2;
        int comp_result = mx_strcmp(arr[mid], (char *)s);

        if (comp_result == 0) {
            *count = c;
            return mid;
        } else if (comp_result < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    *count = 0;
    return -1;
}
