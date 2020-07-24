#include "libmx.h"

/**
 * function that has the same behavior as the standard libc functionmemmove
 */
void *mx_memmove(void *dst, const void *src, size_t len) {
    void *temp = malloc(len);

    if (temp == NULL)
        return NULL;

    mx_memcpy(temp, src, len);
    mx_memcpy(dst, temp, len);
    free(temp);

    return dst;
}
