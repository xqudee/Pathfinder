#include "libmx.h"

unsigned long mx_hex_to_nbr(const char* hex) {
    if (hex == NULL) return 0;
    int count = 0;
    for (; hex[count] != '\0'; count++);
    unsigned long result = 0;
    unsigned long temp = 1;
    for (int i = count - 1; i >= 0; i--) {
        if (hex[i] >= '0'  && hex[i] <= '9') {
            result += ((hex[i] - 48) * temp);
            temp *= 16;
        }
        if ((hex[i] >= 'A' && hex[i] <= 'Z')
            || ('a' <= hex[i] && hex[i] <= 'z')) {
            if (hex[i] >= 'a' && hex[i] <= 'z')
                result += ((hex[i] - 87) * temp);
            if (hex[i] >= 'A' && hex[i] <= 'Z')
                result += ((hex[i] - 55) * temp);
            temp *= 16;
        }
    }
    return result;
}

