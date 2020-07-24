#include <libmx.h>

/**
 * @brief prints wide char character
 * @author Denys Ushakov
 * @version a-1.0
 * @date July 1 2020
 * @example mx_print_unicode('a'); or wchar_t wchr = 'a'; mx_print_unicode(chr);
 * @param c The letter you want to print
 */
void mx_print_unicode(wchar_t c) {
    unsigned char str[5] = {'\0', '\0', '\0', '\0', '\0'};
    if (c < 0x80)
        str[0] = ((c >> 0) & 0x7F) | 0x00;

    else if (c < 0x0800) {
        str[0] = ((c >> 6) & 0x1F) | 0xC0;
        str[1] = ((c >> 0) & 0x3F) | 0x80;
    } else if (c < 0x010000) {
        str[0] = ((c >> 12) & 0x0F) | 0xE0;
        str[1] = ((c >> 6) & 0x3F) | 0x80;
        str[2] = ((c >> 0) & 0x3F) | 0x80;
    } else if (c < 0x110000) {
        str[0] = ((c >> 18) & 0x07) | 0xF0;
        str[1] = ((c >> 12) & 0x3F) | 0x80;
        str[2] = ((c >> 6) & 0x3F) | 0x80;
        str[3] = ((c >> 0) & 0x3F) | 0x80;
    }
    write(1, str, mx_strlen((char *) str));
}
