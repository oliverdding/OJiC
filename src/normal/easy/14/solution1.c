//
// Created by olive on 2/24/2021.
//

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int
find_same_prefix_idx(char *str1, char *str2) {
    int idx = 0;
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        ++idx;
        ++str1;
        ++str2;
    }
    return idx;
}

/**
 * Attention: Please `free` the returned array.
 */
char *
longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    } else if (strsSize == 1) {
        return strs[0];
    }
    int length = 0;
    char *p = strs[0];
    while (*p != '\0') {
        ++length;
        ++p;
    }
    char *tmp = calloc(length + 1, sizeof(char));
    memcpy(tmp, strs[0], length + 1);
    for (int i = 1; i < strsSize; ++i) {
        int idx = find_same_prefix_idx(tmp, strs[i]);
        tmp[idx] = '\0';
    }
    return tmp;
}
