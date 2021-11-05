#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *frontNode = mx_create_node(data);

    frontNode->next = (*list);
    (*list) = frontNode;
}
