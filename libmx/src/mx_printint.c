#include "libmx.h"

/**
 * @brief Prints integer to stdout
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_printint(1337);
 */
void mx_printint(int n) {
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
    } else {
        if (n < 0) {
            mx_printchar('-');
            n = -n;
        }

        if (n / 10)
            mx_printint(n / 10);

        mx_printchar(n % 10 + '0');
    }
}
