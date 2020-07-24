#include "libmx.h"

/**
 * @brief but copies at most n bytes.  If s is  longer  than  n,  only  n  bytes  are
          copied, and a terminating null byte ('\0') is added.
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 */
char *mx_strndup(const char *s1, size_t n) {
    char *string = malloc(n + 1);

    for (size_t i = 0; i < n; i++) {

        if (*s1)
            string[i] = *s1++;
        else
            string[i] = '\0';
    }

    string[n + 1] = '\0';

    return string;
}
