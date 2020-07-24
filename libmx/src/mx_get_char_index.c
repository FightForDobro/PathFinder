#include "libmx.h"

/**
 *
 * • returns the index of the first occurrence
 * • returns -1  if no occurrence is found
 * • returns -2  if the string does not exist
 *
 * @brief finds the index of the first occurrence of the character c  in a string str . A string is a sequence of characters, excluding NULL in the end.
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 * @example
 */
int mx_get_char_index(const char *str, char c) {
    if (str == NULL)
        return -2;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return i;

    return -1;
}
