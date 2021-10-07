#include <iostream>
#include <algorithm>

void Fill_DP (char *str, int DP[][5000], int len) {
    for (int cross = 1; cross < len; cross++) {
        for (int i = 0; i < len-cross; i++) {
            if (str[i] == str[cross+i]) {
                DP[i][cross+i] = DP[i+1][cross+i-1];
            } else {
                DP[i][cross+i] = std::min(DP[i+1][cross+i], DP[i][cross+i-1]) + 1;
            }
        }
    }
    return;
}

int main () {
    int len;
    scanf("%d", &len);
    char str[len + 1];
    scanf("%s", str);
    int DP[len][5000];
    Fill_DP(str, DP, len);
    printf("%d\n", DP[0][len-1]);
    return 0;
}