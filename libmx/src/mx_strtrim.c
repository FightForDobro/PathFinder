#include "libmx.h"

/**
 * • takes a string, and creates a new one from it without whitespace characters at the beginning and the end of the string
 * • frees all unused memory
 * @param str String to trim
 * @return
 * • returns a new trimmed string
 * • returns NULL if the string str does not exist or string trim fails
 */
char *mx_strtrim(const char *str) {
    if (!str || str == NULL) return NULL;

    char *result = mx_strnew(mx_strlen(str));

    /* Delete first part */
    while (mx_is_whitespace(*str++));

    str--;

    mx_strcpy(result, str);
    int str_len = mx_strlen(str) - 1;

    while (mx_is_whitespace(str[str_len]))
        result[str_len--] = '\0';

    if (!result) return NULL;

    return result;
}
