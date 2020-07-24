#include "libmx.h"

/**
 * Implementation of standard func strstr
 * @param haystack
 * @param needle
 * @return
 */
char *mx_strstr(const char *haystack, const char *needle) {
    int needle_len = mx_strlen((char *) needle);

    if (!needle || !needle_len)
        return (char *) haystack;

    while (*haystack) {
        if (*haystack == *needle) {
            if (mx_strncmp((char *) haystack--, (char *) needle, needle_len) == 0) {
                haystack += needle_len - 1;

                return (char *) haystack;
            }
            haystack++;
        }

        haystack++;
    }
    return NULL;
}
