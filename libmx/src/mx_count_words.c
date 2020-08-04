#include "libmx.h"

/**
 * Function counts words in string dived by delimiter
 * @param str String
 * @param c Delimiter
 * @return words count
 */

int mx_count_words(const char *str, char c) {
    if (str == NULL)
        return -1;

    bool word = false;
    int result = 0;

    char *new_str = mx_delete_trailing((char *)str, c);

    while (*new_str) {

        if (*new_str != c)
            word = true;

        if (word && *(new_str + 1) == c && *(new_str + 1) != '\0' && *(new_str + 2) != '\0')
            result++;

        new_str++;
        word = false;
    }

    return word == true ? result : result + 1;
}
