#include "../inc/pathfinder.h"

static void count_Lines(char *splitted_str, char **is1, char **is2, char **cost) {
    int i = 0;
    char *ch = splitted_str;
    
    while(ch[i] != '-') {
        i++;
    }
    *is1 = mx_strndup(ch, i);
    ch += i + 1;
    i = 0;
    while(ch[i] != ',') {
        i++;
    }
    *is2 = mx_strndup(ch, i);
    ch += i + 1;
    i = 0;
    while(ch[i] != '\0') {
        i++;
    }
    *cost = mx_strndup(ch, i);
}

static void check_island(char ***mat, char **splitted_str, int count) {
    char **main = *mat;
    char *cost = NULL;
    char *is1 = NULL;
    char *is2 = NULL;

    int index = 0;
    while(splitted_str[count]) {
        count_Lines(splitted_str[count], &is1, &is2, &cost);

        main[index++] = mx_strdup(is1);
        mx_strdel(&is1);

        main[index++] = mx_strdup(is2);
        mx_strdel(&is2);

        main[index++] = mx_strdup(cost);
        mx_strdel(&cost);

        for (int i = 0; i < index - 3; i += 3) {
            if (mx_strcmp(main[index - 3], main[i]) == 0 && mx_strcmp(main[index - 2], main[i + 1]) == 0) 
            {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
            }
            if (mx_strcmp(main[index - 2], main[i]) == 0 && mx_strcmp(main[index - 3], main[i + 1]) == 0)
            {
                mx_printerr("error: duplicate bridges\n");
                exit(1);
            }
        }
        
        count++;
    }
}

void check_island_main(char **splitted_str, char ***mat) {
    int count = 1;

    while (splitted_str[count]) {
        count++;
    }
    
    *mat = (char **)malloc((count * 3 + 1) * sizeof(char *));

    check_island(&(*mat), splitted_str, 1);
}
