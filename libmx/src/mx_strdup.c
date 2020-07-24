#include "libmx.h"

/**
 * @brief  mx_strdup() function returns a pointer to a new string which is a duplicate of the string s.
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 */
char *mx_strdup(const char *s1) {
    int s1_len = mx_strlen((char *) s1);

    char *duped_string = malloc(s1_len + 1);

    for (int i = 0; i < s1_len + 1; i++)
        duped_string[i] = s1[i];

    return duped_string;
}
