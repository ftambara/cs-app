long lt_cnt = 0;
long ge_cnt = 0;

long absdiff_se(long x, long y) {
    long result;
    if (x < y) {
        lt_cnt++;
        result = y - x;
    }
    else {
        ge_cnt++;
        result = x - y;
    }
    return result;
}

long absdiff(long x, long y) {
    long result;
    if (x < y) {
        result = y - x;
    }
    else {
        result = x - y;
    }
    return result;
}

#include <stdlib.h>

char *caps(const char *str, size_t len) {
    char *copy = (char *)malloc(len);
    char c;
    
    for (size_t i = 0; i < len; i++) {
        c = str[i];
        if (c >= 'a' && c <= 'z') {
            copy[i] = (char)(c + ('A' - 'a'));
        } else {
            copy[i] = str[i];
        }
    }

    return copy;
}
