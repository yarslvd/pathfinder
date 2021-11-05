#include "../inc/pathfinder.h"

static void print_dist(t_final *final, t_main *main) {
    int i = 1;
    int whole_dist = 0;

    mx_printstr("Distance: ");
    if (final->size == 2) {
        mx_printint(main->cost[final->path[0] * main->size + final->path[1]]);
        return;
    }

    while(i < final->size){
        int dist = main->adjm[final->path[i] * main->size + final->path[i + 1]];

        whole_dist += dist;
        mx_printint(dist);

        if(i + 1 < final->size){
            mx_printstr(" + ");
        }
        else{
            mx_printstr("");
        }

        i++;
    }

    mx_printstr(" = ");
    mx_printint(whole_dist);
}

static char *get_name(t_main *main, int i) {
    return main->islands[i];
}

void print_path(t_final *final, t_main *main) {
    static bool first_line = true;

    if (first_line) {
        first_line = false;
    }
    else {
        mx_printstr("\n");
    }
    write(1, "========================================", 40);
    mx_printstr("\n");
    mx_printstr("Path: ");
    mx_printstr(get_name(main, final->path[1]));
    mx_printstr(" -> ");
    mx_printstr(get_name(main, final->path[0]));
    mx_printstr("\n");
    mx_printstr("Route: ");
    for (int i = 1; i < final->size; i++) {
        mx_printstr(get_name(main, final->path[i]));
        mx_printstr(" -> ");
    }
    mx_printstr(get_name(main, final->path[final->size]));
    mx_printstr("\n");
    print_dist(final, main);
    mx_printstr("\n");
    write(1, "========================================", 40);
}
