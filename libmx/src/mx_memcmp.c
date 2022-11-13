#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *arr1 = (char *)s1;
    char *arr2 = (char *)s2;

    size_t len = 0;

    while (len < n && *arr1 && *arr2) {
        if (*arr1 == *arr2) {
            arr1++;
            arr2++;
            len++;
        }
        else return *arr1 - *arr2;
    }

    return 0;
}

