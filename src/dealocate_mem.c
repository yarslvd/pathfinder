#include "../inc/pathfinder.h"

static void del_matrix(int *m) {
    if (m) {
        free(m);
    }
}

void dealocate_mem(t_main *main) {
    mx_del_strarr(&(main->splitted));
    mx_del_strarr(&(main->islands));
    del_matrix(main->adjm);
    del_matrix(main->cost);
}
