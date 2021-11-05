#include "../inc/libmx.h"

bool mx_isalpha(int c) {

    if ((char)c >= 65 && (char)c <= 90) {
        return true;
    }
    else if ((char)c >= 97 && (char)c <= 122) {
        return true;
    }

    return false;
}
