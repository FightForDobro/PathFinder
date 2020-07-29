#include "libmx.h"

bool compare_string(char *x, char *y) {
    return mx_strcmp(x, y) == 0;
}
