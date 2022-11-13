#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (!big || !little || big_len <= 0 || little_len <= 0) return NULL;
    
    char *temp_big = (char *)big;
    char *temp_little = (char *)little;

    while (*temp_big) {
        if (mx_memcmp(temp_big, temp_little, little_len - 1) == 0)
            return temp_big;
        temp_big++;
    }
    return NULL;
}

