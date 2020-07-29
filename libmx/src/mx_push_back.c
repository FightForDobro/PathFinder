#include "libmx.h"

void mx_push_back(t_list **list, void *data) {

    if (list == NULL)
        return;

    if (*list == NULL)
        *list = mx_create_node(data);

    else {
        while (*list)
            list = &(*list)->next;

        *list = mx_create_node(data);
    }
}
