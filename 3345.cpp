#include <cstdio>
#include <algorithm>

int main() {
    int len;
    char pt[301];
    int DP[30001][30001];
    int ret;

    scanf("%d", &len);

    for (int i = 1; i <= len; i++) {
        scanf(" %c", &pt[i]);
    }

    for (int i = 1; i <= len; i++) {
        if (pt[i] == ')') {
            continue;
        }

        if (i < len)
            DP[i][i+1] = 1;
    }

    for (int end = 2; end <= len; end++) {
        for (int start = end - 1; start >=1; start--) {
            if (pt[start] == ')') {
                continue;
            }

            if ((end - start)%2 == 0) {
                continue;
            }
            
            if (end - start > 2)
            DP[start][end] += DP[start][end-2]*DP[end-1][end];

            for (int i = end - 1; i > start + 1; i--) {
                DP[start][end] += DP[start][i-1] * DP[i+1][end-1];
            }
            if (end - start >= 2)
                DP[start][end] += DP[start+1][end-1];
        }
    }
    
    ret = DP[1][len] % 1000000009;
    printf("%d", ret);

    return 0;
}
