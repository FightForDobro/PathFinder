#include "libmx.h"

/**
 * @brief Return square root if result is integer or 0
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_sqrt(4); == 2
 */
int mx_sqrt(int x) {
    if (x == 0)
        return 0;

    else if (x == 1)
        return 1;

    for (int i = 0; i <= x / 2; i++) {
        if (i * i == x)
            return i;
    }

    return 0;
}
