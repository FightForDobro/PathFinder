#include "libmx.h"

/**
 * @brief Print string to stdout
 * @author Denys Ushakov
 * @version a-1.0
 * @date 7/1/2020
 * @example mx_printstr("Some Cool Text");
 */

void mx_printstr(const char *s) {
    write(1, s, mx_strlen((char *)s));
}
