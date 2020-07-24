#include "libmx.h"

/**
 * • takes a pointer to a string
 * • frees string memory with free
 * • sets the string to NULL
 *
 * @brief Delete string
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/7/2020
 *
 */
void mx_strdel(char **str) {
    if (str != NULL && *str != NULL) {
        free(*str);
        *str = NULL;
    }
}
