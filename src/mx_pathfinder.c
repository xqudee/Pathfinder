#include "../inc/header.h"

int get_current_index(char *string) {
    int length = 0;
    for (int i = 0; i < mx_strlen(string); i++) {
        if (string[i] == '\n') length++;
    }
    if (length == 1) return 0;
    for (int i = 0; i < mx_strlen(string); i++) {
        if (string[i] == '\n') {
            length--;
            if (length == 2) return i + 1;
        }
    }
    return 0;
}

char *pathfinder(char *str, char *dist, t_island *islands, int **map, t_data data, int names_count) {
    if (data.from == data.to) {
        int temp = data.distance;
        int length;
        for (length = 0; temp > 0; length++)
            temp /= 10;
        temp = data.distance;
        char sum[length + 1];
        sum[length] = '\0';
        for (int a = 1; temp > 0; a++) {
            sum[length - a] = temp % 10 + 48;
            temp /= 10;
        }
        char *new_route;
        new_route = mx_strnew(mx_strlen(str) + mx_strlen(dist) + length + 100);
        mx_strcpy(new_route, str);
        mx_strcat(new_route, dist);
        mx_strcat(new_route, sum);
        mx_strcat(new_route, "\n========================================\n");
        mx_strdel(&str);
        mx_strdel(&dist);
        return new_route;
    }
    char *prev_str = mx_strdup(&(str[get_current_index(str)]));

    bool first_iter = true;
    for (int i = 0; i < names_count; i++) {
        if (islands[data.from].len - islands[i].len == map[i][data.from]
            && map[i][data.from] != -1) {
            if (!first_iter) {
                char *buf_PR = mx_strjoin(str, prev_str); 
                mx_strdel(&str);
                str = buf_PR;
            }
            char *new_route;
            new_route = mx_strnew(4 + mx_strlen(islands[i].name) + mx_strlen(str));
            mx_strcpy(new_route, str);
            mx_strcat(new_route, " -> ");
            mx_strcat(new_route, islands[i].name);
            mx_strdel(&str);

            int temp = map[i][data.from];
            int length;
            for (length = 0; temp > 0; length++)
                temp /= 10;
            temp = map[i][data.from];
            char bridge[length + 1];
            bridge[length] = '\0';
            for (int a = 1; temp > 0; a++) {
                bridge[length - a] = temp % 10 + 48;
                temp /= 10;
            }
            char *new_dest;
            if (i == data.to && data.distance == islands[data.from].len) {
                new_dest = mx_strdup(dist);
            }
            else {
                new_dest = mx_strnew(3 + length + mx_strlen(dist));
                mx_strcpy(new_dest, dist);
                mx_strcat(new_dest, bridge);
                if (i == data.to) mx_strcat(new_dest, " = ");
                else mx_strcat(new_dest, " + ");
            }
            t_data new_data;
            new_data.distance = data.distance;
            new_data.from = i;
            new_data.to = data.to;
            str = pathfinder(new_route, new_dest, islands, map, new_data, names_count);
            first_iter = false;
        }
    }
    mx_strdel(&prev_str);
    mx_strdel(&dist);
    return str;
}

