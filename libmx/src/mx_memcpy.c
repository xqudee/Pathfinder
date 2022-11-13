#include "libmx.h"

void *mx_memcpy(void *restrictdst, const void *restrictsrc, size_t n) {
    char *dst = (char*)restrictdst;
    char *src = (char*)restrictsrc;
    while (n > 0) {
        *dst++ = *src++;
        n--;
    }
    return dst;
}

