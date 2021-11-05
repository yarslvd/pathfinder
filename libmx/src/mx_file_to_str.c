#include "../inc/libmx.h"

char *mx_file_to_str(const char *filename){
    if(!filename){
        return NULL;
    }

	int buff;

	if((buff = open(filename, O_RDONLY)) == -1){
		mx_printerr("error: file ");
		mx_printerr(filename);
		mx_printerr(" does not exist\n");
		exit(0);
	}

	if(*filename < 0){
		close(buff);
		return NULL;
	}

	int count = 0;
	char c;

    while(read(buff, &c, 1)){
        count++;
    }

    close(buff);

	if(count == 0){
		mx_printerr("error: file ");
		mx_printerr(filename);
		mx_printerr(" is empty\n");
        exit(0);
    }

    int buff1 = open(filename, O_RDONLY);
	char *str = mx_strnew(count);

	read(buff1, str, count);
	close(buff1);
	
	return str;
}
