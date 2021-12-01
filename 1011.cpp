#include <iostream>
#include <vector>
#include <cmath>

int foo(uint64_t a, uint64_t b) {
    int k = 0;
    k = (int)std::pow((double)(b-a), (double)1/2);
    if (b-a == k*k) {
        return 2*k-1;
    } else if (b-a <= k*k + k) {
        return 2*k;
    } else {
        return 2*k + 1;
    }
}

int main () {
    int T;
    std::vector<uint64_t> x, y;
    std::vector<int> ret;

    scanf ("%d", &T);
    for (int i = 0; i < T; i++) {
        uint64_t a, b;
        scanf("%llu %llu", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }

    for (int i = 0; i < T; i++) {
        int k = 0;
        k = foo(x[i], y[i]);
        ret.push_back(k);
    }

    for (int i = 0; i < T; i++) {
        printf("%d\n", ret[i]);
    }

    return 0;
}
