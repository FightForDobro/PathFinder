#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool(*cmp)(void *, void *)) {
    if (!lst)
        return NULL;

    for (t_list *i = lst; i->next != NULL; i = i->next) {
        t_list *s = i;

        for (t_list *j = i->next; j != NULL; j = j->next)
            if (cmp(s->data, j->data))
                s = j;

        void *temp = s->data;
        s->data = i->data;
        i->data = temp;
    }

    return lst;
}
