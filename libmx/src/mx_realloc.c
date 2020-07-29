#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    } else if (!ptr) {
        return malloc(size);
    } else if (size <= malloc_size(ptr)) {
        return ptr;
    } else {
        void *ptrNew = malloc(size);
        if (ptrNew) {
            mx_memcpy(ptrNew, ptr, malloc_size(ptr));
            free(ptr);
        }
        return ptrNew;
    }
}
