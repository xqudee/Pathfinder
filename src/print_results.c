#include "../inc/header.h"

void print_results(t_island *islands, int **matrix, int names_count, int start_ind) {
    for (int end_ind = start_ind + 1; end_ind < names_count; end_ind++) {
        char *result = mx_strnew(59 + (mx_strlen(islands[start_ind].name) * 2) + mx_strlen(islands[end_ind].name));
        mx_strcpy(result, "========================================\nPath: ");
        mx_strcat(result, islands[start_ind].name);
        mx_strcat(result, " -> ");
        mx_strcat(result, islands[end_ind].name);
        mx_strcat(result, "\nRoute: ");
        mx_strcat(result, islands[start_ind].name);

        char *info_dist = mx_strnew(11);
        mx_strcpy(info_dist, "\nDistance: ");

        dijkstra(end_ind, islands, (int**)matrix, names_count);

        t_data data;
        data.from = start_ind;
        data.to = end_ind;
        data.distance = islands[start_ind].len;
        result = pathfinder(result, info_dist, islands, (int**)matrix, data, names_count);

        mx_printstr(result);
        mx_strdel(&result);
    }
    
}

