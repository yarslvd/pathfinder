#include "../inc/pathfinder.h"

void push(t_final *final, int item) {
    if (final->size < final->max_size) {
        
        final->size++;
        final->path[final->size] = item;
    }
}
