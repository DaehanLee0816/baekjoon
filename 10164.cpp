#include <iostream>

int main() {
    int row, col, pos;
    scanf("%d %d %d", &row, &col, &pos);
    int DP[16][16] = {0};
    int ret = 0;
    int pos_y = 1;
    int pos_x = 1;
    int first_path = 0;
    if (pos != 0) {
        pos_y = pos%col == 0 ? pos/col : pos/col + 1;
        pos_x = pos%col == 0 ? col : pos%col;
        printf("%d\n", pos_x);
        printf("%d\n", pos_y);
    }

    DP[1][1] = 1;
    for (int i = 1; i <= pos_y; i++) {
        for (int j = 1; j <= pos_x; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
    }
    first_path = DP[pos_y][pos_x];

    for (int i = pos_y; i <= row; i++) {
        for (int j = pos_x; j <= col; j++) {
            if (i == pos_y && j == pos_x) {
                DP[i][j] = 1;
                continue;
            }
            DP[i][j] = DP[i-1][j] + DP[i][j-1];
        }
    }
    printf("%d\n", first_path);
    printf("%d\n", DP[row][col]);
    ret = first_path * DP[row][col];
    printf("%d", ret);
    return 0;
}