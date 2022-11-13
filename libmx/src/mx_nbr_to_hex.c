#include "libmx.h"

char* mx_nbr_to_hex(unsigned long nbr) {
    unsigned long _nbr = nbr;
    int size = 0;
    while (_nbr != 0) {
        size++;
        _nbr /= 16;
    }
    char* num = mx_strnew(size);
    int i = size - 1;
    while (nbr) {
        int temp = nbr % 16;
        if (temp < 10)
            num[i] += 48 + temp;
        else
            num[i] += 87 + temp;

        i--;
        nbr /= 16;
    }
    return num;
}

