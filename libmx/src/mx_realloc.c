#include "libmx.h"

static int check_size(void **ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        ptr = NULL;
        return 1;
    }

    return 0;
}

/**
 * function that has the same behavior as the standard stdlib functionrealloc
 * @warning FREE WITH FUNCTION `mx_free()`
 */
void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL && size != 0)
        return malloc(size);

    if (check_size(&ptr, size) != 0)
        return malloc(mx_malloc_size(0));

    void *newptr;
    size_t msize = mx_malloc_size(ptr);

    if (size <= msize)
        return ptr;

    newptr = mx_malloc(size);

    if (newptr == NULL)
        return NULL;

    mx_memmove(newptr, ptr, msize);
    free(ptr);
    ptr = NULL;
    return newptr;
}
