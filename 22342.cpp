#include <iostream>
#include <algorithm>

int main () {
    int M, N;
    int D[2002][2002] = {0};
    int DP[2002][2002] = {0};
    int ret = 0;

    scanf ("%d %d", &M, &N);

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            char c;
            scanf(" %c", &c);
            D[i][j] = c - '0';
        }
    }

    for (int i = 1; i <= M; i++) {
        DP[i][1] = D[i][1];
    }

    for (int i = 2; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            DP[j][i] = std::max(DP[j-1][i-1], DP[j][i-1]);
            DP[j][i] = std::max(DP[j][i], DP[j+1][i-1]);
            DP[j][i] += D[j][i];
        }
    }

    for (int i = 1; i <= M; i++) {
        ret = std::max(ret, DP[i][N-1]);
    }

    printf("%d", ret);
    return 0;
}