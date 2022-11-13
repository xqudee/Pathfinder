#include "../inc/header.h"

int *create_arr_of_distances(char *text, int line_count) {
    int *arr_distance = malloc((line_count) * sizeof(int));
    int line = 0;
    while (line < line_count) {
        while (*text != ',') text++;
        text++;
        char **str = mx_strsplit(text, '\n');
        arr_distance[line] = mx_atoi((str[0]));
        mx_del_strarr(&str);
        line++;
        
    }
    return arr_distance;
}

char **create_arr_of_islands(char *text) {
    char *temp = text;
    while (*temp != '\n') temp++;
    temp++;

    int line_count = mx_count_substr(temp, "\n");
    int count_names = line_count * 2;
    char **temp_arr_islands = (char **)malloc((count_names + 1) * sizeof(char*));

    int temp_count = 0;
    while (temp_count < count_names) {
        temp_arr_islands[temp_count] = mx_strndup(temp, (size_t)mx_get_char_index(temp, '-'));
        while (*temp != '-') temp++;
        temp++;
        temp_arr_islands[temp_count + 1] = mx_strndup(temp, (size_t)mx_get_char_index(temp, ','));
        while (*temp != '\n') temp++;
        temp++;
        temp_count += 2;
    }
    temp_arr_islands[count_names] = NULL;

    t_list* list = mx_create_node(temp_arr_islands[0]);
    for (int i = 0; temp_arr_islands[i] != NULL; i++) {
        char *dublicate_name = temp_arr_islands[i];
        for (int j = i + 1; temp_arr_islands[j] != NULL; j++) {
            if (!mx_is_node(list, temp_arr_islands[j])) {
                if (mx_strcmp(dublicate_name, temp_arr_islands[j]) == 0) 
                continue;
                mx_push_back(&list, temp_arr_islands[j]);
            }
        }
    }
    
    t_list* temp_list = list;
    int orig_count = mx_list_size(list);
    char **arr_islands = (char **)malloc((orig_count + 1) * sizeof(char*));
    arr_islands[orig_count] = NULL;
    for (int i = 0; i < orig_count; i++) {
        arr_islands[i] = mx_strdup(temp_list->data);
        temp_list = temp_list->next;
    }

    mx_clear_list(&list);
    mx_del_strarr(&temp_arr_islands);
    return arr_islands;
}

