#include "../inc/libmx.h"

void mx_foreach(int *arr, int size, void (*f)(int)){
    if(size <= 0 || !f || !arr){
        return;
    }
    for (int i = 0; i < size; i++){
        f(arr[i]);
    }
}
