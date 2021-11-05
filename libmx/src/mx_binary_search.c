#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){
    int index;
    int l = 0;
    int r = size - 1;
    
    if (!*arr)
        return -1;
    else {
        while (l <= r) {
            (*count)++;
            index = (r + l) / 2;
            if (mx_strcmp(arr[index], s) < 0){
                l = index + 1;
            }
            else if (mx_strcmp(arr[index], s) > 0){
                r = index - 1;
            }
            else{
                return index;
            }
        }
        *count = 0;
        return -1;
    }
}
