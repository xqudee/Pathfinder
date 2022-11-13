#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) return -2;

    int ind = 0;
    while (*str) {
        if (mx_strncmp(str, sub, mx_strlen(sub)) == 0)
            return ind;
            
        ind++;
        str++;
    }
    return -1;
}

