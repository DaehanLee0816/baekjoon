#include <iostream>
#include <algorithm>
#include <vector>

bool comp (const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] > b[0];
}

int main () {
    int M, N;
    int Map[502][502] = {0};
    int DP[502][502] = {0};

    std::vector<std::vector<int>> s;

    scanf("%d %d", &M, &N);

    std::fill(&Map[0][0], &Map[501][502], INT32_MAX);

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            std::vector<int> e;
            scanf("%d", &Map[i][j]);
            e.push_back(Map[i][j]);
            e.push_back(i);
            e.push_back(j);
            s.push_back(e);
        }
    }

    std::sort(s.begin(), s.end(), comp);

    DP[1][1] = 1;
    for (auto a : s) {
        if (Map[a[1]][a[2]] < Map[a[1] - 1][a[2]] ) {
            DP[a[1]][a[2]] += DP[a[1] - 1][a[2]];
        }

        if (Map[a[1]][a[2]] < Map[a[1] + 1][a[2]] ) {
            DP[a[1]][a[2]] += DP[a[1] + 1][a[2]];
        }

        if (Map[a[1]][a[2]] < Map[a[1]][a[2] - 1] ) {
            DP[a[1]][a[2]] += DP[a[1]][a[2] - 1];
        }

        if (Map[a[1]][a[2]] < Map[a[1]][a[2] + 1] ) {
            DP[a[1]][a[2]] += DP[a[1]][a[2] + 1];
        }

        if (a[1] == M && a[2] == N) {
            break;
        }
    }

    printf("%d", DP[M][N]);
    return 0;
}
