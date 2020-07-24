#include "libmx.h"

int mx_list_size(t_list *list) {
    int size;

    for (size = 0; list != NULL; list = list->next)
        size++;

    return size;
}
