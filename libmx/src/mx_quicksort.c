#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    static int count_of_swap = 0;
    if (left >= right) return count_of_swap;

    char *mid = arr[(left + right) / 2];
    int ind_beg = left;
    int ind_end = right;

    while (ind_beg < ind_end) {
        for (; mx_strlen(arr[ind_beg]) < mx_strlen(mid); ind_beg++);
        for (; mx_strlen(mid) < mx_strlen(arr[ind_end]); ind_end--);
        if (ind_beg <= ind_end) {
            if (mx_strlen(arr[ind_beg]) != mx_strlen(arr[ind_end])) {
                char *temp = arr[ind_beg];
                arr[ind_beg] = arr[ind_end];
                arr[ind_end] = temp;
                count_of_swap++;
            }
            ind_beg++;
            ind_end--;
        }
    }
    mx_quicksort(arr, left, ind_end);
    mx_quicksort(arr, ind_beg, right);
    return count_of_swap;
}

