#include "../inc/libmx.h"

void mx_print_list(t_list *list) {
    if (!list) return;

    while (list) {
        mx_printstr(list->data);
        mx_printchar('\n');
        list = list->next;
    }
}

