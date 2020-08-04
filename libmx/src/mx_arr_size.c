#include "libmx.h"

int mx_char_arr_size(char **arr)
{
    int size = 0;
    while (arr[size++] != NULL);
    return --size;
}