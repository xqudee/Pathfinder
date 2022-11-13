#include "../inc/header.h"

void create_list_of_islands(t_island **islands, char *text, int num_island) {
    char *temp = text;
    char **array_islands = create_arr_of_islands(temp);

    for (int i = 0; i < num_island; i++) {
        (*islands)[i].name = mx_strdup(array_islands[i]);
    }
    mx_del_strarr(&array_islands);
}

char **file_to_array(char *text, int lines_count) {
    char *temp_text = text;
    while(*temp_text != '\n') temp_text++;
    temp_text++;
    char **array_line = (char **)malloc((lines_count + 1) * sizeof(char*));
    array_line[lines_count] = NULL;
    int line = 0;
    while (line < lines_count) {
        array_line[line] = mx_strndup(temp_text, mx_get_char_index(temp_text, '\n'));
        while (*temp_text != '\n') temp_text++;
        temp_text++;
        line++;
    }
    return array_line;
}

int main(int argc, char* argv[]) {
    check_errors(argc, argv);

    char *text = mx_file_to_str(argv[1]);
    int names_count = mx_count_islands(text);
    int lines_count = mx_count_substr(text, "\n") - 1;

    t_island islands[names_count];
    t_island *isl = islands;
    create_list_of_islands(&isl, text, names_count);
    char **array_file = file_to_array(text, lines_count);
    int **matrix = create_matrix(names_count, islands, array_file);

    for (int i = 0; i < names_count; i++)
        print_results(islands, matrix, names_count, i);

    //очищение
    for (int j = 0; j < names_count; j++)
		free(islands[j].name);
    
    for (int j = 0; j < names_count; j++)
		free(matrix[j]);
	free(matrix);

    mx_del_strarr(&array_file);
    mx_strdel(&text);

}

