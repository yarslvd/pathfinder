#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n){
    char *csrc = (char *)src;
    char *cdest = (char *)dst;

    for (size_t i = 0; i < n; i++){
        cdest[i] = csrc[i];
    }
    return cdest;
}
