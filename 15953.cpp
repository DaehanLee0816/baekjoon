#include <iostream>
#include <cmath>

int price_first[6] = {500, 300, 200, 50, 30, 10};
int price_second[5] = {512, 256, 128, 64, 32};

int main() {
    int a[1001];
    int b[1001];
    int cnt;

    scanf("%d", &cnt);
    for (int i = 1; i <= cnt; i++) {
        scanf("%d %d",&a[i], &b[i]);
    }
    
    for (int i = 1; i <= cnt; i++) {
        int ret, rank_f, rank_s;
        ret = 0;
        rank_f = a[i];
        rank_s = b[i];

        if (a[i] <= 21 && a[i] > 0) {
            int r = 0;
            while (rank_f > 0)
            {
                r++;
                rank_f -= r;
            }
            ret += price_first[r-1];
        }

        if (b[i] <= 31 && b[i] > 0) {
            int r = 0;
            while (rank_s > 0)
            {
                r++;
                rank_s -= pow(2, r-1);
            }
            ret += price_second[r-1];
        }

        printf("%d\n", ret*10000);
    }

    return 0;
}