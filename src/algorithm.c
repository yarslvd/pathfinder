#include "../inc/pathfinder.h"

void cost_matrix(t_main *main) {
    main->cost = malloc(main->size * main->size * sizeof(int));
    for (int i = 0; i < main->size; i++) {
        for (int j = 0; j < main->size; j++) {
            main->cost[i * main->size + j] = main->adjm[i * main->size + j];
        }
    }
}

void algorithm(t_main *main) {
    int size = main->size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                int *d = main->cost;
                main->y = d[j * size + i] + d[i * size + k];
                main->x = d[j * size + k];

                if (main->y < main->x) {
                    d[j * size + k] = d[j * size + i] + d[i * size + k];
                }
            }
        }
    }
}
