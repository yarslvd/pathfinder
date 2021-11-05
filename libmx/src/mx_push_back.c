#include "../inc/libmx.h"

/*void mx_push_back(t_list **list, void *data) {
    if(!data){
        return;
    }

    t_list *nodeBack = mx_create_node(data);
    t_list *last = *list;

    if(*list == NULL || list == NULL){
        *list = last;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = nodeBack;
}*/

void mx_push_back(t_list **list, void *data) {
    t_list *new_node = mx_create_node(data);
    t_list *buf = *list;

    if (buf == NULL) {
        *list = new_node;
        return ;
    }
    while (buf->next != NULL)
        buf = buf->next;
    buf->next = new_node;
}

