#include "../inc/pathfinder.h"

int pop(t_final *final) {
    if (final->size > 1) {
        final->size--;

        return final->path[final->size + 1];
    }

    return final->path[1];
}
