#include "libmx.h"

long long mx_atoll(const char *str) {
    int i = 0;
    long long sum = 0;
    int sign = 1;
    char *s = (char *)str;

    while (mx_is_whitespace((s[i]) == true))
        i++;

    if (s[i] == '-') {
        sign = -1;
        i++;
    }

    if (s[i] == '+') {
        sign = 1;
        i++;
    }

    while (mx_isdigit(s[i]) == true)
        sum = sum * 10 + (s[i++] - '0');

    return sum * sign;
}