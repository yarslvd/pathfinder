#include "../inc/pathfinder.h"

static int island_index(t_main *main, char *item) {
    for (int i = 0; i < main->size; i++) {
        if (mx_strcmp(main->islands[i], item) == 0) {
            return i;
        }
    }
    return -1;
}

static void push_item(t_main *main, char *item) {
    int i = 0;

    while(i < main->size){
        if (!main->islands[i]) {
            break;
        }
        if (mx_strcmp(main->islands[i], item) == 0) {
            return;
        }
        i++;
    }
    if (i < main->size) {
        main->islands[i] = mx_strdup(item);
    }
    else {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}

void push_island(t_main *main, char *is1, char *is2, int cost) {
    int i = 0;
    int j = 0;

    main->cost_sum += cost;

    if(main->cost_sum > INT_MAX || main->cost_sum < 0){
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(1);
    }

    push_item(main, is1);
    push_item(main, is2);

    i = island_index(main, is1);
    j = island_index(main, is2);
    main->adjm[main->size * i + j] = cost;
    main->adjm[main->size * j + i] = cost;
}
