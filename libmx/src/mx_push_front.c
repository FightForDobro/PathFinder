#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *new_list;

    if (*list == NULL)
        *list = mx_create_node(data);

    else {
        new_list = malloc(sizeof(t_list));
        new_list->data = data;
        new_list->next = *list;
        *list = new_list;
    }
}
