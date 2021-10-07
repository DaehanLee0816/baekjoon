#include <iostream>

bool is_same(int *orig, int* copy, int len) {
    bool same = true;
    for (int iter = 0; iter < len; iter++) {
        same = true;
        for (int i = 0; i < len; i++) {
            if (orig[(i+iter)%len] != copy[i]) {
                same = false;
            }
        }
        if (same) {
            return true;
        }
    }
    return false;
}

int main () {
    int len;
    scanf("%d", &len);
    int origin[len];
    int reverse_origin[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &origin[i]);
    }

    for (int i = 0; i < len; i++) {
        if (origin[i] != 2) {
            reverse_origin[len-1 - i] = (origin[i] + 2)%4;
        }
        else {
            reverse_origin[len-1 - i] = 4;
        }
    }

    int copies_num;
    scanf("%d", &copies_num);
    int ret = 0;
    bool same[copies_num] = {false};
    int copies[copies_num][len];
    for (int i = 0; i < copies_num; i++) {
        for (int j = 0; j < len; j++) {
            scanf("%d", &copies[i][j]);
        }
    }

    for (int i = 0; i < copies_num; i++) {
        if (is_same(origin, copies[i], len) || is_same(reverse_origin, copies[i], len)) {
            same[i] = true;
            ret++;
        }
    }

    printf("%d\n", ret);
    for (int i = 0; i < copies_num; i++) {
        if (same[i]) {
            for (int j = 0; j < len; j++) {
                printf("%d ", copies[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}