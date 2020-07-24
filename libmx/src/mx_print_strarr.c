#include "libmx.h"

/**
 * @brief Print array of strings
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_print_strarr({"Car", "Cow", "Plane"}, "*");
 */
void mx_print_strarr(char **arr, const char *delim) {
    int size = 0;

    if (!arr || !delim)
        return;

    while (arr[size + 1] != NULL) {
        mx_printstr(arr[size]);
        mx_printstr(delim);
        size++;
    }
    mx_printstr(arr[size]);
}
