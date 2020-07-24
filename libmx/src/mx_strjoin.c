#include "libmx.h"

/**
 *  • concatenates strings s1  ands2  into a new string
 *  • terminates the new string with '\0'
 * @param s1 first string
 * @param s2 second string
 * @return
 * • returns the string as a result of concatenations1  and s2
 * • returns the new copy of non-NULL parameter if one and only one of the parameters is NULL
 * • returns NULL if the concatenation fails
 */
char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;

    if (s1 == NULL)
        return mx_strdup(s2);

    else if (s2 == NULL)
        return mx_strdup(s1);

    char *result = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    mx_strcpy(result, s1);
    mx_strcat(result, s2);

    return result;
}
