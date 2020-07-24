#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (list == NULL)
        return;

    t_list *new_node = mx_create_node(data);
    t_list *t;

    for (t = *list; t != NULL && t->next != NULL; t = t->next);

    t->next = new_node;
}
