#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int c = 0;
    int s = 0;

    if (!str) {
        return -1;
    }

    while (*str == delimiter) {
        str++;
    }

    if (!*str) {
        return 0;
    }

    while (*str) {
        char a = *str++;

        if (a == delimiter && s) {
            continue;
        }

        if (a == delimiter) {
            s = 1;
            c++;
            continue;
        }

        s = 0;
    }

    if (*(str - 1) != delimiter) {
        c++;
    }

    return c;
}
