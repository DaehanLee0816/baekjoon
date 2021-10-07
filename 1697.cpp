#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void take_que(queue<int> &que, int* v, int K) {
    int popped_val;
    popped_val = que.front();
    if (popped_val == K) {
        return;
    }
    if (popped_val > 0 && v[popped_val-1] == 0) {
        que.push(popped_val-1);
        v[popped_val-1] = v[popped_val] + 1;
    }

    if (popped_val < 2*K && v[popped_val+1] == 0) {
        que.push(popped_val+1);
        v[popped_val + 1] = v[popped_val] + 1;
    }

    if (popped_val < K && v[popped_val*2] == 0) {
        que.push(popped_val*2);
        v[popped_val*2] = v[popped_val] + 1;
    }
    que.pop();
}



int main()
{
    int N, K;
    cin >> N >> K;

    if (N >= K) {
        cout << N-K;
        return 0;
    }
    int v[2*K+1] = { 0 };
    queue<int> que;

    que.push(N);
    v[N] = 1;

    while (v[K] == 0) {
        take_que(que, v, K);
    }

    cout << v[K] - 1;
    return 0;
}