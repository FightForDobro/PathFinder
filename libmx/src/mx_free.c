#include "libmx.h"

/**
 * Free for mx_malloc func
 * @param p pointer
 */
void mx_free(void *p) {
    size_t *in = p;

    if (in) {
        --in;
        free(in);
    }
}
