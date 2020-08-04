#include "libmx.h"

bool mx_is_number(char *num){

    if (num == NULL || !*num)
        return false;

    while (*num)
        if (!mx_isdigit(*num++))
            return false;

    return true;
}
