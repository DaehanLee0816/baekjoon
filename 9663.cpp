#include <iostream>

#define map_size 16
int ret = 0;
int N;
int map[map_size][map_size];

void fill(int &x, int &y) {
    int i, j;
    for (i = 1; i <= N; i++) {
        map[y][i]++;
    }

    for (i = 1; i <= N; i++) {
        map[i][x]++;
    }

    i = y;
    j = x;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]++;
        i++;
        j++;
    }

    j = x;
    i = y;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]++;
        i--;
        j--;
    }

    i = y;
    j = x;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]++;
        i++;
        j--;
    }

    i = y;
    j = x;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]++;
        i--;
        j++;
    }
}

void erase(int &x, int &y) {
    int i, j;
    for (i = 1; i <= N; i++) {
        map[y][i]--;
    }

    for (i = 1; i <= N; i++) {
        map[i][x]--;
    }

    i = y;
    j = x;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]--;
        i++;
        j++;
    }

    j = x;
    i = y;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]--;
        i--;
        j--;
    }

    i = y;
    j = x;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]--;
        i++;
        j--;
    }

    i = y;
    j = x;
    while (i >=1 && i <= N && j >= 1 && j <= N) {
        map[i][j]--;
        i--;
        j++;
    }
}

void DFS(int &x) {
    if (x == N) {
        for (int i = 1; i <= N; i++) {
            if (map[i][x] == 0) {
                ret++;
                break;
            }
        }
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (map[i][x] == 0) {
            //for (int a = 1; a <= N; a++) {
            //    for (int b = 1; b <= N; b++) {
            //        printf("%d ", map[a][b]);
            //    }
            //    printf("\n");
            //}
            fill(x, i);
            //for (int a = 1; a <= N; a++) {
            //    for (int b = 1; b <= N; b++) {
            //        printf("%d ", map[a][b]);
            //    }
            //    printf("\n");
            //}
            x++;
            DFS(x);
            x--;
            erase(x, i);
        }
    }
}


int main () {
    scanf("%d", &N);
    int start = 1;
    DFS(start);
    printf("%d", ret);
    return 0;
}