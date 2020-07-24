#include "libmx.h"

/**
 * Implementation of standard func strcpy
 * @param dst where to copy
 * @param src from copy
 * @return return dst
 */
char *mx_strcpy(char *dst, const char *src) {
    for (int i = 0; (dst[i] = src[i]) != '\0'; i++);
    return dst;
}
