#include "libmx.h"

int mx_binary_search(char** arr, int size, const char* s, int* count) {
    int left = 0;
    int right = size - 1;
    if (left > right) return -1;
    int mid = (left + right) / 2;
    
    while (left <= right) {
        (*count)++;
        
        if (mx_strcmp(arr[mid], s) > 0)
            right = mid - 1;
        else if (mx_strcmp (arr[mid], s) < 0)
            left = mid + 1;
        else                      
            return mid;

        mid = (left + right) / 2;
    }
    *count = 0;
    return -1;
}

