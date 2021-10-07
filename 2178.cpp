#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

static int N, M;

void take_queue(int *road, int *map, bool *is_visited_map, queue<int> &que) {
    int popped_val;
    popped_val = que.front();
    
    if (popped_val % M != 0) {
        if (road[popped_val-1] == 1) {
            if (is_visited_map[popped_val-1] == false ||
                map[popped_val-1] > map[popped_val]+1) {
                is_visited_map[popped_val-1] = true;
                map[popped_val-1] = map[popped_val] + 1;
                que.push(popped_val-1);
            }
        }
    }
    
    if (popped_val > M) {
        if (road[popped_val-M] == 1) {
            if (is_visited_map[popped_val-M] == false ||
                map[popped_val-M] > map[popped_val]+1) {
                is_visited_map[popped_val-M] = true;
                map[popped_val-M] = map[popped_val] + 1;
                que.push(popped_val-M);
            }
        }
    }
    
    if (popped_val % M != M-1) {
        if (road[popped_val+1] == 1) {
            if (is_visited_map[popped_val+1] == false ||
                map[popped_val+1] > map[popped_val]+1) {
                is_visited_map[popped_val+1] = true;
                map[popped_val+1] = map[popped_val] + 1;
                que.push(popped_val+1);
            }
        }
    }
    
    if (popped_val < (N-1)*M) {
        if (road[popped_val+M] == 1) {
            if (is_visited_map[popped_val+M] == false ||
                map[popped_val+M] > map[popped_val]+1) {
                is_visited_map[popped_val+M] = true;
                map[popped_val+M] = map[popped_val] + 1;
                que.push(popped_val+M);
            }
        }
    }
    que.pop();
}

int main()
{
    bool is_longer_width;
    cin >> N >> M;
    if (M > N) {
        is_longer_width = true;
    }
    char row[M];
    int map[N*M] = { 0 };
    int road[N*M] = { 0 };
    bool map_checking_visited[N*M] = {false};
    for (int i=0; i < N; i++) {
        cin >> row;
        for (int j=0; j < M; j++) {
            if (row[j] == '1') {
                road[i*M + j] = 1;
            }
        }
    }
    
    queue<int> que;
    map_checking_visited[0] = true;
    que.push(0);
    map[0]=1;
    while (map[N*M - 1] == 0) {
        take_queue(road, map, map_checking_visited, que);
    }
    
    cout << map[N*M-1];
    return 0;
}