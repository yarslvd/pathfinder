#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {
    int l1 = mx_strlen(s1);
    int l2 = mx_strlen(s2);

    for (int i = 0; i < l1; i++) {

        if(mx_strncmp(&s1[i], s2, l2) == 0) {
            return mx_strchr(&s1[i], s1[i]);
        }

    }
    return 0;
}
