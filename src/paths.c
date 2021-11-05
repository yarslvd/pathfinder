#include "../inc/pathfinder.h"

static int obtain(t_final *final) {
    return final->path[final->size];
}

static bool following(t_final *final, t_main *main, int next) {
    int index = obtain(final);
    int i = final->path[0];
    int size = main->size;
    int *d = main->cost;
    int *adj = main->adjm;

    if (index != next) {
        if (d[index * size + i] - adj[index * size + next] == d[next * size + i]) {
            return true;
        }
    }

    return false;
}

static void store(t_final **final, t_main *main, int j, int i) {
    *final = malloc(sizeof(t_final));

    if (!(*final)) {
        exit(1);
    }

    (*final)->max_size = main->size;
    (*final)->path = malloc(((*final)->max_size + 1) * sizeof(int));
    (*final)->path[1] = i;
    (*final)->path[0] = j;
    (*final)->size = 1;
}

void allpaths(t_final *final, t_main *main) {
    int i = 0;

    if (obtain(final) == final->path[0]) {
        print_path(final, main);
        return;
    }

    while(i < main->size){
        if (following(final, main, i)) {
            push(final, i);
            allpaths(final, main);
            pop(final);
        }
        i++;
    }
}

static void paths_to(t_main *main, int j, int i) {
    t_final *final = NULL;

    store(&final, main, j, i);
    allpaths(final, main);

    free(final->path);
    free(final);
}

void paths_main(t_main *main) {
    for (int i = 0; i < main->size - 1; i++) {
        for (int j = i + 1; j < main->size; j++) {
            paths_to(main, j, i);
        }
    }
    mx_printstr("\n");
}
