#include <iostream>
#include <vector>

int main()
{
    int size;
    scanf("%d", &size);
    int map[21][21];
    int sum_map[21][21] = {0};
    int height[21];
    int ret[21] = {0};
    int DP[21][21][40000] = {-1, };
    int sum = 0;
    int ret_diff;

    printf("%d", size);
    
    for (int y = size; y >= 1; y--) {
        for (int x = 1; x <= size; x++) {
            scanf("%d", &map[x][y]);
            sum += map[x][y];
        }
    }

    for (int x = 1; x <=size; x++) {
        for (int y = 1; y <= size; y++) {
            sum_map[x][y] += (sum_map[x][y-1] + map[x][y]);
        }
    }

    for (int y = 0; y <= size; y++) {
        DP[1][y][sum_map[1][y]] = std::abs(sum - 2*sum_map[1][y]);
    }

    for (int x = 1; x < size; x++) {
        for (int y = 0; y <= size; y++) {
            int min = INT32_MAX;
            for (int i = y; i <=size; i++) {
                for (int temp_sum = 0; temp_sum < size*size*100; temp_sum++) {
                    if (DP[x][i][temp_sum] == -1)
                        continue;
                    
                    DP[x+1][i][temp_sum + sum_map[x+1][i]] = std::abs(sum - 2*(temp_sum + sum_map[x+1][i]));
                }
            }
        }
    }

    int min = INT32_MAX;
    int prev_sum;
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j <= 100*size*size; j++) {
            if (min > DP[size][i][j]) {
                min = DP[size][i][j];
                ret[size] = i;
                prev_sum = j;
                ret_diff = DP[size][i][j];
            }
        }
    }
    
    for (int i = size - 1; i >= 1; i++) {
        for (int j = 1; j <= size; j++) {
            if (DP[i][j][prev_sum - sum_map[i][ret[i+1]]] != -1) {
                ret[i] = j;
                prev_sum -= sum_map[i][ret[i+1]];
            }
        }
    }

    printf("%d\n", ret_diff);
    
    for (int i = 1; i < size; i++) {
        printf("%d ",ret[i]);
    }
    printf("%d", ret[size]);
    return 0;
}