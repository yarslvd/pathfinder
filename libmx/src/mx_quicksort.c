#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr){
        return -1;
    }

    int count = 0;

    if (left < right) {
        int m = left;
        int n = right;
        char *pivot = arr[(n + m) / 2];

        while (m <= n) {
            while (mx_strlen(arr[m]) < mx_strlen(pivot)) m++;
            while (mx_strlen(arr[n]) > mx_strlen(pivot)) n--;

            if (m <= n) {
                if (mx_strlen(arr[n]) != mx_strlen(arr[m])) {
                    char *buff = arr[m];
                    arr[m] = arr[n];
                    arr[n] = buff;
                    count++;
                }
                n--;
                m++;
            }
        }

        count += mx_quicksort(arr, left, n);
        count += mx_quicksort(arr, m, right);
    }    
    return count;
}

