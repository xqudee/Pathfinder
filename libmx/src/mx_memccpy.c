#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    if (!dst || !src || n <= 0) return NULL;

    size_t len = 0;
    char *src_1 = (char *)src;
    char *dst_1 = (char *)dst;

    while (len < n && *src_1) {
        if (*src_1 == (char)c) {
            *dst_1++ = *src_1;
            *dst_1 = '\0';
            return dst_1;
        }
        else {
            *dst_1++ = *src_1++;
            len++;
        }
    }

    return NULL;
}

