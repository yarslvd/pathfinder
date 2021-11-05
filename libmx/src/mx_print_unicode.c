#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c){
    if (c<0x80) {
        char buff[1];
		buff[0] = (c >> 0 & 0x7F) | 0x00;
		write(1, &buff, 1);
	}
	else if (c<0x0800) {
        char buff[2];
		buff[0] = (c >> 6 & 0x1F) | 0xC0;
		buff[1] = (c >> 0 & 0x3F) | 0x80;
		write(1, &buff, 2);
	}
	else if (c<0x010000) {
        char buff[3];
		buff[0] = (c >> 12 & 0x0F) | 0xE0;
		buff[1] = (c >> 6 & 0x3F) | 0x80;
		buff[2] = (c >> 0 & 0x3F) | 0x80;
		write(1, &buff, 3);
	}
	else {
        char buff[4];
		buff[0] = (c >> 18 & 0x07) | 0xF0;
		buff[1] = (c >> 12 & 0x3F) | 0x80;
		buff[2] = (c >> 6 & 0x3F) | 0x80;
		buff[3] = (c >> 0 & 0x3F) | 0x80;
		write(1, &buff, 4);
	}
}
