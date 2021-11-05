#include "../inc/pathfinder.h"

static void adjmat(t_main *main) {
    main->adjm = malloc(main->size * main->size * sizeof(int));

    for (int i = 0; i < main->size; i++) {
        for (int j = 0; j < main->size; j++) {

            if (i == j) {
                main->adjm[main->size * i + j] = 0;
            }
            else {
                main->adjm[main->size * i + j] = INT_MAX;
            }
        }
    }
}

static bool parse_line(char *line, char **is1, char **is2, int *cost, int i) {
    char *num = NULL;
    int dash = mx_get_char_index(line, '-');
    int comma = mx_get_char_index(line, ',');
    int len = mx_strlen(line);

    if (dash == -1 || comma == -1 || dash > comma || len == 0) {
        return false;
    }

    *is1 = mx_strndup(line, dash);
    *is2 = mx_strndup(line + dash + 1, comma - dash - 1);

    if(mx_strcmp(*is1, *is2) == 0){
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(i + 1));
        mx_printerr(" is not valid\n");
        free(*is1);
        free(*is2);
        exit(1);
    }

    num = mx_strndup(line + comma + 1, len - comma - 1);
    *cost = mx_atoi(num);
    if (*cost == -1 || !(*cost)){
        return false;
    }
    free(num);
    return true;
}

static void islands_init(t_main *main) {
    main->islands = malloc((main->size + 1) * sizeof(char*));
    if (!main->islands) {
        exit(1);
    }
    for (int i = 0; i < main->size + 1; i++) {
        main->islands[i] = NULL;
    }
}


void parse_str(t_main *main) {
    int i = 0;
    char **mat = NULL;

    islands_init(main);
    adjmat(main);
    check_island_main(main->splitted, &mat);
    mx_del_strarr(&mat);

    while(main->splitted[i] != NULL){

        char *is1 = NULL;
        char *is2 = NULL;
        int cost = -1;

        if (parse_line(main->splitted[i], &is1, &is2, &cost, i)) {
            push_island(main, is1, is2, cost);
        }
        else{
            free(is1);
            free(is2);
        }
        free(is1);
        free(is2);
        i++;
    }
}

void mat_init(t_main *main) {
    main->islands = NULL;
    main->adjm = NULL;
    main->cost = NULL;

    parse_str(main);
    if (!main->islands[main->size - 1]) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
