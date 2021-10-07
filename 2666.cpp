#include <iostream>
#include <string.h>
#include <cstdlib>

int main() {
    int num_closet;
    int opened_closet[2];
    int list_num;
    int closet_list[20];
    int DP[21][21];
    memset(DP, -1, sizeof(DP));
    scanf("%d", &num_closet);
    scanf("%d %d", &opened_closet[0], &opened_closet[1]);
    scanf("%d", &list_num);
    for (int i = 0; i < list_num; i++) {
        scanf("%d", &closet_list[i]);
    }
    if (closet_list[0] != opened_closet[0] && closet_list[0] != opened_closet[1]) {
        DP[closet_list[0]][opened_closet[0]] = std::abs(closet_list[0] - opened_closet[1]);
        DP[closet_list[0]][opened_closet[1]] = std::abs(closet_list[0] - opened_closet[0]);
    }
    else {
        DP[closet_list[0]][opened_closet[0]] = 0;
        DP[closet_list[0]][opened_closet[1]] = 0;
    }

    for (int i = 1; i < list_num; i++) {
        if (closet_list[i] == closet_list[i-1])
            continue;

        for (int j = 1; j <= num_closet; j++) {
            int val = INT32_MAX;
            if (j == closet_list[i-1]) {
                for (int k = 1; k <= num_closet; k++) {
                    if (DP[closet_list[i-1]][k] == -1)
                        continue;
                    val = std::min(val, DP[closet_list[i-1]][k] + std::abs(k - closet_list[i]));
                }
                DP[closet_list[i]][j] = val;
                continue;
            }
            if (DP[closet_list[i-1]][j] == -1)
                continue;
            if (DP[closet_list[i-1]][closet_list[i]] != -1)
                val = std::min(val, DP[closet_list[i-1]][closet_list[i]] + std::abs(closet_list[i] - j));
                
            val = std::min(val, DP[closet_list[i-1]][j] + std::abs(closet_list[i] - closet_list[i-1]));

            DP[closet_list[i]][j] = val;
        }

        for (int j = 1; j <= num_closet; j++) {
            DP[closet_list[i-1]][j] = -1;
        }
    }

    int ret = INT32_MAX;
    for (int i = 1; i <= num_closet; i++) {
        if (DP[closet_list[list_num-1]][i] == -1)
            continue;
        
        ret = std::min(ret, DP[closet_list[list_num-1]][i]);
    }

    printf("%d", ret);
    return 0;
}