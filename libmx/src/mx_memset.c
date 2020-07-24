#include "libmx.h"

/**
 * Function that has the same behavior as the standard libc functionmemset
 */
void *mx_memset(void *b, int c, size_t len) {
    unsigned char *ptr = (unsigned char *) b;

    for (size_t i = 0; i < len; i++)
        ptr[i] = (unsigned char) c;

    return b;
}
