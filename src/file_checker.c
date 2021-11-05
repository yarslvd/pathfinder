#include "../inc/pathfinder.h"

void check_endlines(char *file_str){
    int d = 1;
    for(int i = 0; file_str[i]; i++){
        if(file_str[i] == '\n'){
            d++;
            if(file_str[i + 1] == '\n')
            {
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(d));
                mx_printerr(" is not valid\n");
                exit(1);
            }
        }
    }
    if(file_str[0] == '\n'){
        mx_printerr("error: line 1 is not valid\n");
        exit(1);
    }
    else if(file_str[0] == '0'){
        mx_printerr("error: line 1 is not valid\n");
        exit(1);
    }
}

int mx_get_char_index(const char *str, char c) 
{
    if (!str) return -2;
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) return i;
    }
    return -1;
}

static void check_islands(t_main *main) {
    if (mx_strlen(*main->splitted) > 4) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
    main->size = mx_atoi(*main->splitted);
    if (!main->size && !main->splitted[1]) {
        exit(1);
    }
    if (!main->size && main->splitted[1]) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}

int count_lines(char **splitted_str){
    int lines_count = 0;
    while(splitted_str[lines_count]){
        lines_count++;
    }
    return lines_count - 1;
}

void check_delimeters(char **splitted_str){
    char **str = splitted_str;
    bool dash = false;
    bool comma = false;
    int zero = 1;
    int i = 1;
    int d1 = 0;
    int d2 = 0;

    while(str[i]){
        for(int j = 0; str[i][j] != '\0'; j++){
            if(str[i][j] == '-'){
                d1++;
            }
            if(str[i][j] == ',' && d1 == 1){
                d2++;
            }
        }
        if(d1 != 1 || d2 != 1){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(1);
        }
        d1 = 0; d2 = 0;
        i++;
    }

    for(int i = 1; str[i] != NULL; i++){
        for(int j = 0; str[i][j] != '-'; j++){
            if(!mx_isalpha(str[i][j])){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(1);
            }
        }
        if(!mx_isalpha(str[i][0])){
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(1);
        }
        for(int j = 0; str[i][j] != ','; j++){
            if(str[i][j] == '-'){
                dash = true;
                j++;
            }
            if(dash == true && !mx_isalpha(str[i][j])){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(1);
            }
        }
        dash = false;
        for(int j = 0; str[i][j] != '\0'; j++){
            zero++;
            if(str[i][j] == ','){
                comma = true;
                zero = 0;
                j++;
            }
            if(str[i][j] == '0' && zero == 0){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(1);
            }
            if(comma == true && !mx_isdigit(str[i][j])){
                mx_printerr("error: line ");
                mx_printerr(mx_itoa(i + 1));
                mx_printerr(" is not valid\n");
                exit(1);
            }
            comma = false;
        }
        
    }

}

int parse_file(char **splitted_str, t_main *main){
    int i = 0;
    main->size = mx_atoi(*splitted_str);

    while(splitted_str[0][i]){
        if(!mx_isdigit(splitted_str[0][i])){
            mx_printerr("error: line 1 is not valid\n");
            exit(1);
        }
        i++;
    }

    check_delimeters(splitted_str);
    count_lines(splitted_str);
    check_islands(main);

    return 0;
}
