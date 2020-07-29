#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *cur = list;
    int ret = 0;

    while (cur) {
        cur = cur->next;
        ret++;
    }
    return ret;
}
