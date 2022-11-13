#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"

#define MAX_INT 2147483647

void check_errors(int argc, char* argv[]);
char **create_arr_of_islands(char *text);
int *create_arr_of_distances(char *text, int line_count);
void find_path(int **path/*, c *names*/, int names_count, int start_ind, char** list_islands);
int mx_count_islands(char *text);

typedef struct s_island {
    char *name;
    int len;
} t_island;

typedef struct s_data {
    int from;
    int to;
    int distance;
} t_data;

void dijkstra(int start, t_island *islands, int **matrix, int names_count);
char *pathfinder(char *route, char *dist, t_island *islands, int **map, t_data data, int names_count);
int **create_matrix(int names_count, t_island list_islands[names_count], char **array_file);
void print_results(t_island *islands, int **matrix, int names_count, int start_ind);

#endif

