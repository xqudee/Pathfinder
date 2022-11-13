#include "../inc/header.h"

void dijkstra(int start, t_island *islands, int **matrix, int names_count) {
    bool block[ names_count];
    for (int i = 0; i <  names_count; i++) {
        islands[i].len = MAX_INT;
        block[i] = false;
    }
    islands[start].len = 0;
    int current = start;
    for (int a = 0; a <  names_count; a++) {
        block[current] = true;
        for (int i = 0; i < names_count; i++) {
            if (matrix[i][current] != -1) {
                if (islands[i].len > matrix[i][current] + islands[current].len && !block[i]) {
                    islands[i].len = matrix[i][current] + islands[current].len;
                }
            }
        }
        int min = MAX_INT;
        for (int i = 0; i <  names_count; i++) {
            if (islands[i].len < min && !block[i]) {
                current = i;
                min = islands[i].len;
            }
        }
    }
}

