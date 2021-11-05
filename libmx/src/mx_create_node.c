#include "../inc/libmx.h"

t_list *mx_create_node(void *data){

    t_list* newNode = (t_list*)malloc(sizeof(t_list));

    if(newNode == NULL){
        return NULL;
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
