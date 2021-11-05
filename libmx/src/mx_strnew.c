#include "../inc/libmx.h"

char *mx_strnew(const int size) {
	if (size < 0) {
		return NULL;
	}

	char *buff = (char *)malloc((size + 1) * sizeof(char));

	if (buff == NULL) {
		return NULL;
	}
	for (int i = 0; i <= size; i++) {
		buff[i] = '\0';
	}

	return buff;
}
