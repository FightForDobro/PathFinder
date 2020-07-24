#include "libmx.h"

void mx_pop_back(t_list **head) {
    if (head == NULL || *head == NULL)
        return;

    t_list *templist = *head;

    while (templist->next->next != NULL)
        templist = templist->next;

    free(templist->next);
    templist->next = NULL;
}
