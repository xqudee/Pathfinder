#include "libmx.h" 

void mx_clear_list(t_list** list) {
    if (!(*list)) return;

    while (*list) {
        t_list* node = (*list)->next;
        if (node == NULL) {
            //free((*list)->data);
            free(*list);
            *list = NULL;
            return;
        }
        node = (*list)->next;
        free(*list);
        *list = node;
    }
}

