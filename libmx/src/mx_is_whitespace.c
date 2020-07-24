#include "libmx.h"

bool mx_is_whitespace(char chr) {
    return (chr >= 8 && chr <= 13) || chr == 32;
}
