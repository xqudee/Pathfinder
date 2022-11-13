#include "libmx.h"

void mx_str_reverse(char *s) {
    if (!s) return;

    char* new_s = mx_strnew(mx_strlen(s));
    int j = mx_strlen(s) - 1;
    for (int i = 0; i < mx_strlen(s); i++) {
        new_s[i] = s[j];
        j--;
    }
    s = mx_strcpy(s, new_s);
    mx_strdel(&new_s);
}

