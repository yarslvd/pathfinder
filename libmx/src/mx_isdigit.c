#include "../inc/libmx.h"

bool mx_isdigit(int c) {

    if ((char)c >= 48 && (char)c <= 57) {
        return true;
    }

    return false;
}
