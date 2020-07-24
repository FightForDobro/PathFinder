#include "libmx.h"

/**
 * @brief Return integer digits count
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/5/2020
 * @example mx_intlen(256); == 3
 */
int mx_intlen(int num) {
    int len = 1;

    while (num /= 10)
        len++;

    return len;
}
