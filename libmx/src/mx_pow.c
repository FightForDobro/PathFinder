#include "libmx.h"

/**
 * @brief Return result of pow
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_pow(2, 5) == 32
 * @param n number
 * @param pow power of number
 */
double mx_pow(double n, unsigned int pow) {
    double res = 1;

    for (unsigned int i = 0; i < pow; i++)
        res *= n;

    return res;
}
