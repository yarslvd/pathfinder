#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define INT_MAX 2147483647

typedef struct s_main {
    char **splitted;
    char **islands;
    int *cost;
    int cost_sum;
    int *adjm;
    int size;
    size_t x;
    size_t y;
}           t_main;

typedef struct s_final {
    int *path;
    int max_size;
    int size;
}           t_final;

int parse_file(char **splitted_str, t_main *main);
void check_delimeters(char **splitted_str);
void check_endlines(char *file_str);
void algorithm(t_main *main);
void cost_matrix(t_main *main);
void push(t_final *final, int item);
int pop(t_final *final);
void print_path(t_final *final, t_main *main);
void paths_main(t_main *main);
void dealocate_mem(t_main *main);
void createArray(char **lines, char ***arrarr);
void mat_init(t_main *main);
void check_island_main(char **lines, char ***arrarr);
void push_island(t_main *main, char *is1, char *is2, int cost);

#endif
