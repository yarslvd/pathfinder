#include "../inc/libmx.h"

char *mx_strtrim(const char *str){
    if(str == NULL){
        return NULL;
    }

    int s = mx_strlen(str);
    int sp1 = 0;
    int sp2 = 0;

    for(int i = 0; i < mx_strlen(str); i++){
        if(mx_isspace(str[i])){
            sp1++;
        }
        else{
            break;
        }
    }
    for(int i = mx_strlen(str) - 1; i > sp1; i--){
        if(mx_isspace(str[i])){
            sp2++;
        }
        else{
            break;
        }
    }
    int new_s = s - (sp1 + sp2);
    char *buffer = mx_strnew(new_s);
    return mx_strncpy(buffer, &str[sp1], new_s);
}
