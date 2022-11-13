#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char unicode[4];

    if (c < 128) {
        unicode[0] = c;
        unicode[1] = '\0';
        write(1, &unicode, 1);
        return;
    }

    if (c > 1114112 || (c >= 0xd800 && c <= 0xdfff)) {
        unicode[0] = 0xef;
        unicode[1] = 0xbf;
        unicode[2] = 0xbd;
        unicode[3] = 0x00;
        write(1, &unicode, 3);
        return;
    }

    wchar_t size = 0;
    if (c < 2048) size = 2;
    else if (size < 65536) size = 3;
    else size = 4;

    unsigned char m = 128;
    wchar_t ind = 0;
    unicode[0] = 0x00;
    while (ind < size) {
        unicode[0] |= m;
        ind++;
        m /= 2;
    }
    
    ind = 1;
    while (ind < size) {
        unicode[ind] = (char)128;
        ind++;
    }

    int temp = size - 1;
    while(temp >= 0) {
        m = 1;
        ind = 0;
        while (c && ind < 6) {
            if (c % 2) unicode[temp] |= m;
            c /= 2;
            m *= 2;
            ind++;
        }
        temp--;
    }
    unicode[size] = '\0';
    write(1, &unicode, size);
    
}

