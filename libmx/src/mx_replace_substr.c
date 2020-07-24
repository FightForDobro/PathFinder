#include "libmx.h"

/**
 * Function that replaces all occurrences ofsubinstrwithreplace
 * @param str String
 * @param sub Substring
 * @param replace string to replace sub
 * @return modified string
 */
char *mx_replace_substr(const char *str, const char *sub, const char *replace){
    int sub_len = mx_strlen(sub);
    char *string = mx_strnew(mx_strlen(str) + (mx_strlen(replace) * mx_count_substr(str, sub)));
    int sub_index = mx_get_substr_index(str, sub);

    while (sub_index != -1)
    {
        mx_strncat(string, str, sub_index);
        mx_strcat(string, replace);

        str += sub_len + sub_index;
        sub_index = mx_get_substr_index(str, sub);
    }

    mx_strcat(string, str);
    return string;
}
