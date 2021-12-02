#include <iostream>
#include <queue>
#include <algorithm>

int N = 0;

void Search(int (*M)[1501], std::queue<int>& R, std::queue<int>& C, std::queue<int>& val, int& ret) {
    int min = UINT8_MAX;
    int r, c, v;

    r = R.front();
    c = C.front();
    v = val.front();

    //search adjacent rows
    for (int i = 1; i <= N; i++) {
        if (std::abs(r - i) != 1)
            continue;
        for (int j = 1; j <= N; j++) {
            if (std::abs(c - j) <= 1)
                continue;

            if (M[i][j] <= M[r][c])
                continue;
            min = std::min(min, M[i][j]);
        }
    }

    //search adjacent columns
    for (int j = 1; j <= N; j++) {
        if (std::abs(c - j) != 1)
            continue;
        for (int i = 1; i <= N; i++) {
            if (std::abs(r - i) <= 1)
                continue;

            if (M[i][j] <= M[r][c])
                continue;
            min = std::min(min, M[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (std::abs(r - i) != 1)
            continue;
        for (int j = 1; j <= N; j++) {
            if (std::abs(c - j) <= 1)
                continue;

            if (M[i][j] <= M[r][c])
                continue;
            if (M[i][j] == min) {
                R.push(i);
                C.push(j);
                val.push(v+1);
                ret = v+1;
            }
        }
    }

    for (int j = 1; j <= N; j++) {
        if (std::abs(c - j) != 1)
            continue;
        for (int i = 1; i <= N; i++) {
            if (std::abs(r - i) <= 1)
                continue;

            if (M[i][j] <= M[r][c])
                continue;
            if (M[i][j] == min) {
                R.push(i);
                C.push(j);
                val.push(v+1);
                ret = v+1;
            }
        }
    }

    R.pop();
    C.pop();
    val.pop();
}

int main() {
    int R,C;
    int M[1501][1501] = {0};
    std::queue<int> row, col, val;
    int ret = 0;

    scanf("%d", &N);
    scanf("%d %d", &R, &C);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    row.push(R);
    col.push(C);
    val.push(1);
    ret = 1;
    
    while (!row.empty()) {
        Search(M, row, col, val, ret);
    }

    printf("%d", ret);
    return 0;
}
