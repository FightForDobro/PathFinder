#include "libmx.h"

/**
 * @brief Converts unsigned long to hex (string)
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_nbr_to_hex(256); = "100";
 */
char *mx_nbr_to_hex(unsigned long nbr) {
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int hex_len = mx_get_hex_digits_count(nbr);

    char *result = malloc(sizeof(char) * hex_len + 1);
    result[hex_len] = '\0';

    for (int i = (hex_len - 1) * 4, index = 0; hex_len; i -= 4, index++, hex_len--)
        result[index] = hexDigits[(nbr >> i) & 15];

    return result;
}
