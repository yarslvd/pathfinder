#include "../inc/libmx.h"

char *mx_itoa(int number) {
    bool f = false;

    if (number < 0) {
        f = true;
		number *= -1;
	}

    int buff = number;
	int len = 0;
    char *numStr = NULL;

	while(buff > 0) {
        buff /= 10;
		len++;
	}

    numStr = mx_strnew(len);

    if (number == 0)
		return mx_strcpy(numStr, "0");
	if (number == -2147483648)
		return mx_strcpy(numStr, "-2147483648");
    if (f) {
		numStr[0] = '-';
	}
    if(f) {
        for (int i = len; i > 0; i--) {
            numStr[i] = number % 10 + 48;
            number /= 10;
        }
    }
    else {
        for (int i = len - 1; i >= 0; i--) {
            numStr[i] = number % 10 + 48;
            number /= 10;
        }
    }
    return numStr;
}
