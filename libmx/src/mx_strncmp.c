#include "libmx.h"

/**
 * Compare s1 and s2 and to n
 * @param s1 First string
 * @param s2 Second string
 * @param n number of bytes to check
 * @return deference of incorrect char
 */
int mx_strncmp(char *s1, char *s2, int n)
{
    while(n--)
        if(*s1++!=*s2++)
            return *(unsigned char*)(s1 - 1) - *(unsigned char*)(s2 - 1);
    return 0;
}
