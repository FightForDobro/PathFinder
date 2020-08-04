#include "libmx.h"

bool mx_isalpha(char chr)
{
    return (chr > 64 && chr < 91) || (chr > 96 && chr < 123);
}