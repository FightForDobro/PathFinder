#include "libmx.h"

/**
 * Implementation of func strncpy;
 * @param dst where to copy
 * @param src from copy
 * @param len num of char to copy
 * @return dst
 */
char *mx_strncpy(char *dst, const char *src, int len) {
    while (len-- && *src) {
        *dst = *src++;
        dst++;
    }

    *dst = *src;

    return dst;
}
