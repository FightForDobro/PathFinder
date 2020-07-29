#include "libmx.h"

/**
 * Function return index of substring start
 * @param str String
 * @param sub Substring
 * @return index of substring
 */
int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub)
        return -2;

    int sub_len = mx_strlen((char *)sub);

    for (int i = 0; str[i]; i++)
        if (str[i] == sub[0])
            if (mx_strncmp((char *)(str + i), (char *)sub, sub_len) == 0)
                return i;

    return -1;
}
