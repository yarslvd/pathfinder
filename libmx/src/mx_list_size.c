#include "../inc/libmx.h"

int mx_list_size(t_list *list){
    if(list == NULL){
        return 0;
    }

    int counter = 0;

    t_list *buff = list;
    while(buff){
        buff = buff->next;
        counter++;
    }
    return counter;
}
