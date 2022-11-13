#include "../inc/header.h"

int search_ind_in_list(t_island *list, void * value){
    int i = 0;
	for (; list[i].name != NULL; i++){
		if (mx_strcmp(value, list[i].name) == 0) return i;
	}
	return -1;
}

int **create_matrix(int names_count, t_island *list_islands, char **array_file) {
    int **matrix = malloc(names_count*sizeof(int *));
	for (int i = 0; i < names_count; i++) {
		matrix[i] = malloc(names_count*sizeof(int));
		for (int j = 0; j < names_count; j++)
			matrix[i][j] = -1;
    }

    for (int i = 0; array_file[i] != NULL; i++) {
        char **island = mx_strsplit(array_file[i], ',');
        char **name_island = mx_strsplit(island[0], '-');
        char *name_1 = name_island[0];
        char *name_2 = name_island[1];
        int num = mx_atoi(island[1]);
        int ind_from = search_ind_in_list(list_islands, name_1);
        int ind_to = search_ind_in_list(list_islands, name_2);
        matrix[ind_from][ind_to] = num;
        matrix[ind_to][ind_from] = num;
        mx_del_strarr(&island);
        mx_del_strarr(&name_island);
    }
    return matrix;
}

