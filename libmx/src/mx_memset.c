#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    char *temp = (char*)b;
    while (len > 0) {
        *temp++ = (char)c;
        len--;
    }
    return temp;

}

