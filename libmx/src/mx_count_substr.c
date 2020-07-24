#include "libmx.h"

/**
 * Function counts substrings in string
 * @param str string
 * @param sub substring
 * @return substrings count
 */
int mx_count_substr(const char *str, const char *sub) {
    /* Base cases */
    if (!str || !sub)
        return -1;

    if (!*sub)
        return 0;

    int count = 0;

    /************************************ Very beautiful part of code *************************************************/
    for (int i = mx_get_substr_index(str, sub); i != -1 && *str; count++, i = mx_get_substr_index(str, sub))
        str = &str[i + mx_strlen((char *) sub)];
    /******************************************************************************************************************/

    return count;
}
