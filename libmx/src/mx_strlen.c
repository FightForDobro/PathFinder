#include "libmx.h"

/**
 * @brief Returns string len
 * @author Denys Ushakov
 * @version a-1.0
 * @date 6/30/2020
 */
int mx_strlen(const char *string) {
    int len = 0;

    while (string[len])
        len++;

    return len;
}
