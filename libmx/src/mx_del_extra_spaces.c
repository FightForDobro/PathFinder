#include "libmx.h"

/**
 * • takes a string, and creates a new one from it without whitespace characters in the beginning and/or at the end of the string
 * • separates words in the new string with exactly one space character• frees all unused memory
 * @param str
 * @return
 * • returns a new created string
 * • returns NULL if the string str does not exist or string creation fails
 */
char *mx_del_extra_spaces(const char *str) {
    if (!str || str == NULL) return NULL;
    char *new_str = mx_strtrim(str);
    char *res;
    int i = 0;
    int j = 0;

    while (new_str[i] != '\0') {
        if (mx_is_whitespace(new_str[i])) {
            new_str[j] = ' ';
            j++;
            while (mx_is_whitespace(new_str[i]))
                i++;
        }
        new_str[j++] = new_str[i++];
    }
    new_str[j] = '\0';
    res = mx_strnew(j);
    res = mx_strncpy(res, new_str, j + 1);
    mx_strdel(&new_str);
    if (!res) return NULL;
    return res;
}
