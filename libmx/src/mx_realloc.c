#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    //size_t len = malloc_usable_size(ptr); 
    size_t len = malloc_size(ptr);
    if (size <= len) return ptr;

    void *temp = malloc(size);
    mx_memcpy(temp, ptr, len);
    free(ptr);
    return temp;
}

