#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2){
    int s1_sz = mx_strlen(s1);
    int s2_sz = mx_strlen(s2);
    int i = s1_sz;
    int j = 0;

    while (i < (s1_sz + s2_sz)){
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i++] = '\0';
    return s1;
}
