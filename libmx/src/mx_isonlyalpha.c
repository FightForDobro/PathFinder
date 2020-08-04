#include "libmx.h"

bool mx_isonlyalpha(char *string)
{
    if (!string || string == NULL || !*string)
        return false;

    while (*string)
        if(!mx_isalpha(*string++))
            return false;

    return true;
}