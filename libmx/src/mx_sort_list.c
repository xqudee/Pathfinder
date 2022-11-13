#include "libmx.h"

t_list* mx_sort_list(t_list* list, bool (*cmp)(void* a, void* b)) {
    if (list == NULL || cmp == NULL)
        return list;

    t_list* node = list;
    while (node) {
        t_list* temp_node = list;
        while (temp_node->next) {
            if (cmp(temp_node->data, temp_node->next->data)) {
                void* temp = temp_node->data;
                temp_node->data = temp_node->next->data;
                temp_node->next->data = temp;
            }
            temp_node = temp_node->next;
        }
        node = node->next;
    }
    return list;
}

