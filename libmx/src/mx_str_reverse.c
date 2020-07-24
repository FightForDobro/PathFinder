#include "libmx.h"

/**
 * @brief reverses a string using pointers. Do nothing if a string does not exist
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 */
void mx_str_reverse(char *s) {
    if (s) {
        int len = mx_strlen(s);

        for (int i = 0; i < len / 2; i++)
            mx_swap_char(&s[i], &s[len - i - 1]);
    }
}
