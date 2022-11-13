#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if ( !lineptr || buf_size <= 0 || !delim || fd <= 0)
        return -2;
    
    char ch;
    int lenght = 0;

    if (read(fd, &ch, 1)) {
        if (ch == delim) return 0;

        *lineptr = mx_realloc(*lineptr, lenght + 1);
        (*lineptr)[lenght] = ch;
    }
    else return -1;
    
    while (read(fd, &ch, 1)) {
        if (ch == delim) break;

        lenght++;
        *lineptr = mx_realloc(*lineptr, lenght + 1);

        (*lineptr)[lenght] = ch;
    }

    //size_t free_bytes = malloc_usable_size(*lineptr) - lenght; 
    size_t free_bytes = malloc_size(*lineptr) - lenght;
    mx_memset(&(*lineptr)[lenght + 1], '\0', free_bytes);

    return lenght + 1;
}

