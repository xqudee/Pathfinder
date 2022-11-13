#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    if (!s) return NULL;

    char *arr = (char *)s + mx_strlen((char *)s);
    size_t len = 0;

    while (len <= n) {
        if (*arr == c) return arr;
        arr--;
        len++;
    } 

    return NULL;
}

