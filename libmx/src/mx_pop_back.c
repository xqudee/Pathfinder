#include "libmx.h"

void mx_pop_back(t_list** head) {
    if (!head || !(*head)) return;
    
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    t_list* temp = *head;
    while (temp->next->next != NULL && temp)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

