#include "libmx.h"

/**
 * Check string_int for overflow-
 * @param num
 * @return true if num is correct false in case of error or incorrect
 */
bool mx_check_str_int(char *num)
{
    if (num == NULL || mx_strlen(num) > 10 || num[0] == '-')
        return false;

    if (mx_strlen(num) < 10)
        return true;

    for (int i = 0; i < 10; i++) {
        switch (i)
        {
            case 0:
                if (num[i] - 48 > 2)
                    return false;
                break;
            case 1:
                if (num[i] - 48 > 1)
                    return false;
                break;
            case 2:
                if (num[i] - 48 > 4)
                    return false;
                break;
            case 3:
                if (num[i] - 48 > 7)
                    return false;
                break;
            case 4:
                if (num[i] - 48 > 4)
                    return false;
                break;
            case 5:
                if (num[i] - 48 > 8)
                    return false;
                break;
            case 6:
                if (num[i] - 48 > 3)
                    return false;
                break;
            case 7:
                if (num[i] - 48 > 6)
                    return false;
                break;
            case 8:
                if (num[i] - 48 > 4)
                    return false;
                break;
            case 9:
                if (num[i] - 48 > 7)
                    return false;
                break;
        }
    }

    return true;
}
