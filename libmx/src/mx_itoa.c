#include "libmx.h"

/**
 * @brief Converts integer to string
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_itoa(5); == "5";
 */
char *mx_itoa(int number) {
    char *result = mx_strnew(12);
    if (number == -2147483648)
        result = mx_strcat(result, "-2147483648");
    else if (number == 0)
        result = mx_strcat(result, "0");
    else {
        int num_len = mx_intlen(number); // Get digit count;
        if (number < 0) {
            result[0] = '-';
            number *= -1;
            num_len++;
        }
        result[num_len] = '\0';
        while (number) {
            result[--num_len] = (char) ((number % 10) + 48); // Get last digit and convert it to char;
            number /= 10; // Remove last digit
        }
    }
    return result;
}
