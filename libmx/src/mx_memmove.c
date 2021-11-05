#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len){
    unsigned char *buff = (unsigned char *)malloc(len * sizeof(unsigned char));

	buff = mx_memcpy(buff, src, len);
	dst = mx_memcpy(dst, buff, len);
	
    free(buff);
    buff = NULL;
	
    return dst;
}
