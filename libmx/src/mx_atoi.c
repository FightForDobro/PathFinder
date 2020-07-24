#include "libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int sum = 0;
    int sign = 1;
    char *s = (char *)str;

    while (mx_is_whitespace((s[i++]) == true));

    if (s[i++] == '-')
        sign = -1;

    if (s[i++] == '+')
        sign = 1;

    while (mx_isdigit(s[i]) == true)
        sum = sum * 10 + (s[i++] - '0');

    return sum * sign;
}
