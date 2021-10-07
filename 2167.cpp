#include <iostream>
#include <vector>

using namespace std;

void sum(vector<vector<int>> &map, vector<int> &ret, int i, int j, int x, int y) {
    int sum_ret = 0;
    for (int a = i; a <= x; a++) {
        for (int b = j; b<= y; b++) {
            sum_ret += map[b-1][a-1];
        }
    }
    ret.push_back(sum_ret);
}

int main()
{
    int N, M, k, i, j, x, y;
    cin >> N >> M;
    
    vector<vector<int>> map;
    vector<int> ret;
    
    for (int a = 0; a < N; a++) {
        vector<int> i_th_row;
        for (int b = 0; b < M; b++) {
            int elem;
            cin >> elem;
            i_th_row.push_back(elem);
        }
        map.push_back(i_th_row);
    }
    
    cin >> k;
    for (int a = 0; a < k; a++) {
        cin >> i >> j >> x >> y;
        sum(map, ret, i, j, x, y);
    }
    
    for (int a = 0; a < ret.size(); a++) {
        cout << ret[a] << endl;
    }
    
    return 0;
}