#include "libmx.h"
#include "stdio.h"

/**
 *
 * • takes a pointer to a NULL-terminated array of strings
 * • deletes the contents of the array
 * • frees array memory with free
 * • sets a pointer to NULL
 *
 * @brief Delete array of strings
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 */
void mx_del_strarr(char ***arr) {
    if (arr != NULL && *arr != NULL) {

        char **strings = *arr;
        int count = 0;

        while (strings[count])
            mx_strdel(&strings[count++]);

        free(*arr);
        *arr = NULL;
    }
}
