#include "libmx.h"

/**
 * @brief Return digit count from dec to hex
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/5/2020
 * @example mx_get_hex_digits_count(256); == 3
 */

int mx_get_hex_digits_count(unsigned long num) {
    for (int i = 0; num != 0; i++) {
        double res1 = (mx_pow(16, i));

        double res2 = mx_pow(16, i + 1);

        if (num >= res1 && num < res2)
            return i + 1;
    }

    return 1;
}
