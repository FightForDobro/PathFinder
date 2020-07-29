#include "libmx.h"

/**
 * Implementation of func strncpy;
 * @param dst where to copy
 * @param src from copy
 * @param len num of char to copy
 * @return dst
 */
char *mx_strncpy(char *dst, const char *src, int len) {
    char *ptr = &*dst;
    dst[len] = '\0';
    while (len-- && (*dst++ = *src++));
    return ptr;
}
