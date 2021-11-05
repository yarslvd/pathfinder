#include "../inc/libmx.h"

static int len(unsigned long num) {
    int l = 0;

    while (num) {
        num /= 16;
        l++;
    }
    return l;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *buff = NULL;
    unsigned long num = nbr;
    int l = len(nbr);
    int t;

    buff = malloc(l);
    if (nbr == 0)
        return mx_strcpy(buff, "0");
    while (num) {
        t = num % 16;
        if (t < 10)
            buff[--l] = 48 + t;
        if (t >= 10)
            buff[--l] = 87 + t;
        num /= 16;
    }
    return buff;
}
