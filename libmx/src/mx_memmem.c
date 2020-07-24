#include "libmx.h"

/**
 * function that has the same behavior as the standard libc function memmem
 */
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *big_s = (unsigned char *) big;
    const unsigned char *little_s = (const unsigned char *) little;

    if (big_len < little_len || little_len == 0 || big_len == 0 || big_s == NULL || little_s == NULL)
        return NULL;

    if (little_len == 1)
        return mx_memchr(big, (char) little_s[0], big_len);

    for (size_t i = 0; i < big_len; i++)
        if (big_s[i] == little_s[0])
            if (mx_memcmp(big_s, little_s, little_len))
                return big_s + i + little_len;

    return NULL;
}
