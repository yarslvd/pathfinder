#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *new = NULL;
    char *buff = NULL;
    int i = 0;
    int j = 0;

    if (!str){
        return NULL;
    }
    
    new = mx_strnew(mx_strlen(str));

    while (str[i]) {
        if (!(mx_isspace(str[i]))) {
            new[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            new[j] = ' ';
            j++;
        }
        i++;
    }

    buff = mx_strtrim(new);
    mx_strdel(&new);
    return buff;
}
