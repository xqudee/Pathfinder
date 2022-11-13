#include "libmx.h"

int mx_insertion_sort(char** arr, int size) {
    int count = 0;
    for (int i = 1; i < size; i++) {
        char* temp = arr[i];
        int j = i - 1;
        for (; j >= 0 && mx_strlen(arr[j]) > mx_strlen(temp); j--) {
            arr[j + 1] = arr[j];
            count++;
        }
        arr[j + 1] = temp;
    }
    return count;
}

