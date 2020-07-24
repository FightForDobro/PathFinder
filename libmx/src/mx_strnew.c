#include "libmx.h"

/**
 * Function create new string and fill it with '\0' and adds +1 byt for terminating
 * @param size size of string
 * @return new string
 */
char *mx_strnew(const int size) {
    char *result = malloc(sizeof(char) * size + 1);

    if (!result)
        return NULL;

    for (int i = 0; i <= size + 1; i++)
        result[i] = '\0';

    return result;
}
