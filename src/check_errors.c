#include "../inc/header.h"

void error_1(int argc) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }
}

void error_2(int file, char* file_name) {
    if (file == -1) {
        mx_printerr("error: file ");
        mx_printerr(file_name);
        mx_printerr(" does not exist\n");
        exit(-1);
    }
}

void error_3(char *text, char* file_name) {
    if (mx_strlen(text) == 0) {
        mx_printerr("error: file ");
        mx_printerr(file_name);
        mx_printerr(" is empty\n");
        mx_strdel(&text);
        exit(-1);
    }
}

void error_4(char *text) {
    char *temp = text;
    int i = 0;
    while (temp[i] != '\n') {
        if (!mx_isdigit(temp[i])) {
            mx_printerr("error: line 1 is not valid\n");
            mx_strdel(&text);
            exit(-1);
        }
        i++;
    }
}

void print_err(int line) {
    char *str = mx_itoa(line);
    mx_printerr("error: line ");
    mx_printerr(str);
    mx_printerr(" is not valid\n");
    mx_strdel(&str);
}

void error_5(char *text, int line_count) {
    char *temp = text;
    while(*temp != '\n') temp++;

    int line = 1;

    while (line_count != line) {
        line++;
        temp++;

        if (*temp == '-') {
            print_err(line);
            mx_strdel(&text);
            exit(-1);
        }

        char **island1 = mx_strsplit(temp, '-');

        while (*temp != '-') {
            if (*temp == '\n' || !mx_isalpha(*temp))  {
                print_err(line);
                mx_del_strarr(&island1);
                mx_strdel(&text);
                exit(-1);
                return;
            }
            temp++;
        }

        char **island2 = mx_strsplit(temp, ',');
        if (mx_strcmp(island1[0], island2[0] + 1) == 0) {
            print_err(line);
            mx_del_strarr(&island1);
            mx_del_strarr(&island2);
            mx_strdel(&text);
            exit(-1);
            return;
        }

        temp++;
        mx_del_strarr(&island1);
        mx_del_strarr(&island2);

        while (*temp != ',') {
            if (*temp == '\n' || !mx_isalpha(*temp)) {
                print_err(line);
                mx_strdel(&text);
                exit(-1);
                return;
            }
            temp++;
        }
        temp++;

        while (*temp != '\n') {
            if (!mx_isdigit(*temp)) {
                print_err(line);
                mx_strdel(&text);
                exit(-1);
                return;
            }
            temp++;
        }
    }
}

int mx_count_islands(char *text) {
    char *temp_text = text;
    char **num_str = mx_strsplit(temp_text, '\n');
    int num_island = mx_atoi(num_str[0]);
    mx_del_strarr(&num_str);
    return num_island;
}

int error_6(char **islands, int num_island) {
    int i = 0;
    for (; islands[i] != NULL; i++);
    if (i != num_island) {
        mx_printerr("error: invalid number of islands\n");
        return -1;
    }
    return 0;
}

char *make_reverse(char *temp_arr_islands) {
    char *str_reverse = mx_strnew(mx_strlen(temp_arr_islands));
    char *str_temp = mx_strdup(temp_arr_islands);
    char *s = str_temp;
    while (*s != '-') s++;
    s++;
    str_reverse = mx_strcat(str_reverse, s);  
    str_reverse = mx_strcat(str_reverse, "-");
    s = str_temp;
    s = mx_strncpy(s, s, mx_get_char_index(s, '-'));
    mx_strcat(str_reverse, s);
    mx_strdel(&str_temp);  
    return str_reverse;
}

int error_7(char *text) {
    int err = 0;
    char *temp = text;
    while (*temp != '\n') temp++;
    temp++;

    int line_count = mx_count_substr(temp, "\n");
    char **temp_arr_islands = (char **)malloc((line_count + 1) * sizeof(char*));

    int temp_count = 0;
    while (temp_count < line_count) {
        temp_arr_islands[temp_count] = mx_strndup(temp, (size_t)mx_get_char_index(temp, ','));
        while (*temp != '\n') temp++;
        temp++;
        temp_count++;
    }
    temp_arr_islands[line_count] = NULL;

    t_list* list = mx_create_node(temp_arr_islands[0]);
    for (int j = 1; temp_arr_islands[j] != NULL; j++) {
        char *str_reverse = make_reverse(temp_arr_islands[j]);

        if (!mx_is_node(list, temp_arr_islands[j]) && !mx_is_node(list, str_reverse)) {
            mx_push_back(&list, temp_arr_islands[j]);
            mx_strdel(&str_reverse);
        }
        else {
            err = -1;
            mx_printerr("error: duplicate bridges\n");
            mx_strdel(&str_reverse);
            break;
        }
    }
    mx_clear_list(&list);
    mx_del_strarr(&temp_arr_islands);

    return err;
}

int error_8(char *text) {
    int err = 0;
    char *temp = text;
    while (*temp != '\n') temp++;
    temp++;
    int line_count = mx_count_substr(temp, "\n");
    int *arr_distance = create_arr_of_distances(temp, line_count);
    double all_distance = 0;
    for (int i = 0; i < line_count; i++) {
        int temp = arr_distance[i];
        all_distance += temp;
    }
    if (all_distance > MAX_INT) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        err = -1;
    } 
	free(arr_distance);
    return err;
}

void check_errors(int argc, char* argv[]) {

    error_1(argc);

    bool is_error = false;
    char* file_name = argv[1]; 
    int file = open(file_name, O_RDONLY);
    char *text = NULL;
    int line_count = 0;
    char **list_islands = NULL;

    error_2(file, file_name);
    text = mx_file_to_str(file_name);
    line_count = mx_count_substr(text, "\n");
    error_3(text, file_name);
    error_4(text);
    error_5(text, line_count);

    list_islands = create_arr_of_islands(text);

    int num_island = mx_count_islands(text);
    if (error_6(list_islands, num_island) == -1) is_error = true;
    
    if (!is_error)
        if (error_7(text) == -1) is_error = true;

    if (!is_error)
        if (error_8(text) == -1) is_error = true;
    
    mx_del_strarr(&list_islands);
    mx_strdel(&text); 

    if (is_error) exit(-1);
}


