#include <iostream>
#include <vector>

int main() {
    int N;
    scanf("%d", &N);
    int H[N], W[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &H[i], &W[i]);
    }

    int ret[N] = {0};
    
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (H[i] < H[j] && W[i] < W[j]) {
                cnt++;
            }
        }
        ret[i] = cnt + 1;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}