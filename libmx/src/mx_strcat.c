#include "libmx.h"

/**
 * Implementation of standard func strcat
 * @param s1 First string
 * @param s2 Second string
 * @return s1
 */
char *mx_strcat(char *s1, const char *s2) {
    int s1_len = mx_strlen(s1), s2_len = mx_strlen(s2);
    int i;

    for (i = 0; i < s2_len; i++)
        s1[s1_len + i] = s2[i];

    s1[s1_len + i] = '\0';

    return s1;
}
