#include "../inc/libmx.h"

bool mx_isdigit(int c) {
    if (c >= 48 && c <= 57) {
        return true;
    }
    return false;
}

bool mx_isalpha(int c) {
	if (c >= 65 && c <= 90) {
		return true;
	}
	if(c >= 97 && c <= 122) {
		return true;
	}
	return false;
}

bool mx_isupper(int c) {
	if (c >= 65 && c <= 90) {
        return true;
    }
    return false;
}

bool mx_islower(int c) {
	if (c >= 97 && c <= 122) {
        return true;
    }
    return false;
}

unsigned long mx_hex_to_nbr(const char *hex) {
	if (hex == NULL) {
		return 0;
	}

    int len = 0;
	unsigned long base = 1;
	unsigned long res = 0;

	while (hex[len] != '\0') {
		if (!mx_isdigit(hex[len]) 
		&& !mx_isalpha(hex[len])) {
			return 0;
		}

		if (mx_isalpha(hex[len])) {
			if (mx_isupper(hex[len])
			&& (hex[len] < 65 || hex[len] > 70)) {
				return 0;
			}

			if (mx_islower(hex[len])
            && (hex[len] < 97 || hex[len] > 102)) {
				return 0;
			}
		}

		len++;
	}

	for (int i = len - 1; i >= 0; i--) {
		if (mx_isdigit(hex[i])) {
	            res += (hex[i] - 48) * base;
	            base *= 16;
	        }
	        else if (mx_isupper(hex[i])) {
	            res += (hex[i] - 55) * base;
	            base *= 16;
	        }
	        else if (mx_islower(hex[i])) {
	            res += (hex[i] - 87) * base;
	            base *= 16;
	        }
	}
	
	return res;
}
