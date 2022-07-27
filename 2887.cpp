#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

bool has_same_root (int a[], int i, int j) {
    int root1, root2, temp1, temp2;
    temp1 = i;
    temp2 = j;
    while (a[temp1] != temp1) {
        temp1 = a[temp1];
    }

    while (a[temp2] != temp2) {
        temp2 = a[temp2];
    }

    return temp1 == temp2;
}

void change_root(int a[], int i, int j) {
    if (a[i] < a[j]) {
        a[j] = a[i];
    } else {
        a[i] = a[j];
    }
}

bool cmp (std::vector<int> &e1, std::vector<int> &e2) {
    return e1[0] < e2[0];
}

int main() {
    int N;
    int ans = 0;
    int edge_cnt = 0;
    std::vector<std::vector<int>> pos_arr;
    std::vector<std::vector<int>> edges;
    int root[100000];

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z;
        std::vector<int> pos;
        std::cin >> x >> y >> z;
        pos.push_back(x);
        pos.push_back(y);
        pos.push_back(z);
        pos_arr.push_back(pos);
        root[i] = i;
    }
    
    for (int dim = 0; dim < 3; dim++) {
        for (int i = 0; i < N-1; i++) {
            int dist = INT32_MAX;
            for (int j = i+1; j < N; j++) {
                dist =  std::min(dist, std::abs(pos_arr[i][dim] - pos_arr[j][dim]));
            }
            for (int j = i+1; j < N; j++) {
                if (dist == std::abs(pos_arr[i][dim] - pos_arr[j][dim])) {
                    std::vector<int> E = {dist, i, j};
                    edges.push_back(E);
                }
            }
        }
    }

    std::sort(edges.begin(), edges.end(), cmp);
    
    //for (auto it = edges.begin(); it != edges.end(); it++) {
    //    std::cout << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << std::endl;
    //}

    for (int i = 0; i < edges.size(); i++) {
        if (edge_cnt == N-1) {
            break;
        }
        bool same_root = has_same_root(root, edges[i][1], edges[i][2]);
        if (!same_root) {
            ans += edges[i][0];
            edge_cnt++;
            change_root(root, edges[i][1], edges[i][2]);
        } else {
            continue;
        }
    }
    std::cout << ans;
    return 0;
}