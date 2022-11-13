#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    char *dst_temp = (char *)dst;
    char *src_temp = (char *)src;

    if (dst > src || dst_temp < src_temp + len) {
        dst_temp = dst_temp + len - 1;
        src_temp = src_temp + len - 1;
        while (len) {
            *dst_temp-- = *src_temp--;
            len--;
        }
    }
    else 
        while (len) {
            *dst_temp++ = *src_temp++;
            len--;
        }

    return dst_temp;
}

