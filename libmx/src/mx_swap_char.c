#include "libmx.h"

/**
 * @brief swaps the characters of a string using pointers. Do nothing ifs1ors2  does not exist
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 * @example
 */
void mx_swap_char(char *s1, char *s2) {
    if (*s1 && *s2) {
        char temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }
}
