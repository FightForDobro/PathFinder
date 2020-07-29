#include "libmx.h"

/**
 * Function that has the same behavior as the standard stdlib functionmemcmp
 */
int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *string1 = (unsigned char *)s1;
    unsigned char *string2 = (unsigned char *)s2;

    for (size_t i = 0; i < n; i++)
        if (string1[i] != string2[i])
            return string1[i] - string2[i];

    return 0;
}
