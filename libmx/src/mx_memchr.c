#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    if (!s) return NULL;

    char *arr = (char *)s;
    size_t len = 0;

    while (*arr && len < n) {
        if (*arr == c) return arr;
        else {
            arr++;
            len++;
        }
    }
    return NULL;
}

