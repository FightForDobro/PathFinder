#include "libmx.h"

/**
 * @brief Converts hex to unsigned long
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_hex_to_nbr("F"); == 15
 */
unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL) return 0;
    unsigned long result = 0;
    int hex_len = mx_strlen((char *) hex) - 1;

    while (*hex) {
        if (*hex <= 9)
            result += (unsigned long) ((*hex++ - 48) * mx_pow(16, hex_len--));

        else
            result += (unsigned long) ((*hex++ - 55) * mx_pow(16, hex_len--));
    }

    return result;
}
