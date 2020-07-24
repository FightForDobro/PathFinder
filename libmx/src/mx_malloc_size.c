#include "libmx.h"

/**
 * Function get size of malloced pointer
 * @param p pointer
 * @return size of pointer
 */
size_t mx_malloc_size(void *p) {
    size_t *in = p;

    if (in) {
        --in;
        return *in;
    }

    return -1;
}
