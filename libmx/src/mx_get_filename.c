#include "../inc/libmx.h"

char* mx_get_filename(char* argv) {
    if (mx_count_substr(argv, "/") == 0) {
        return argv;
    }

    else {
        mx_printint(10);
        int i = mx_strlen(argv);
        while (argv[i] != '/')
            i--;
        char *str = mx_strnew(5);
        for (i++; argv[i] != ' '; i++) 
            mx_strcat(str, &argv[i]);
        return str;
    }
}

