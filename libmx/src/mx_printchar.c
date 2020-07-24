#include "libmx.h"

/**
 * @brief prints ASCII character from 0-255
 * @author Denys Ushakov
 * @version a-1.0
 * @date June 30 2020
 * @example mx_printchar('a'); or char chr = 'a'; mx_printchar(chr);
 * @param c The letter you want to print
 */
void mx_printchar(char c) {
    write(1, &c, 1);
}
