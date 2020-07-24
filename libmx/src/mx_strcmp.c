#include "libmx.h"

/**
 * Implementation of standard func strcmp
 * @param s1 First string
 * @param s2 Second string
 * @return return deference of incorrect char
 */
int mx_strcmp(char *s1, char *s2) {
    int i = 0;

    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return 0;

        i++;
    }

    return s1[i] - s2[i];
}
