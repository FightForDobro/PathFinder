#include "libmx.h"

/**
 * Make string from parts
 * @param parts parts of string
 * @param size_of_array
 * @return new_string
 */
char *mx_makestring(char **parts, size_t size_of_array)
{
    char *new_string = mx_strnew(0);

    while (size_of_array--)
        new_string = mx_strjoin(new_string, *(parts)++);

    return new_string;
}

