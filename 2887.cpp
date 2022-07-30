#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/* Kruskal Algorithm - edges set 설정이 중요하다. */

// edge의 각 node에 대한 parent를 확인하여 cycle이 형성되는 edge인지 확인
bool has_same_root (int a[], int i, int j) {
    int temp1, temp2;
    temp1 = i;
    temp2 = j;
    while (a[temp1] != temp1) {
        temp1 = a[temp1];
    }
    a[i] = temp1;

    while (a[temp2] != temp2) {
        temp2 = a[temp2];
    }
    a[j] = temp2;
    if (a[i] == a[j])
        return true;

    return false;
}

// 보고있는 edge의 node에 대해서만 parent를 update하는것이 아닌 각 node의 parent에 대한 update가 수행되어야함
void change_root(int a[], int i, int j) {
    if (a[i] < a[j]) {
        a[a[j]] = a[i];
    } else {
        a[a[i]] = a[j];
    }
}

bool cmp_e (std::vector<int> &e1, std::vector<int> &e2) {
    return e1[0] < e2[0];
}

bool cmp_x (std::vector<int> &e1, std::vector<int> &e2) {
    return e1[1] < e2[1];
}

bool cmp_y (std::vector<int> &e1, std::vector<int> &e2) {
    return e1[2] < e2[2];
}

bool cmp_z (std::vector<int> &e1, std::vector<int> &e2) {
    return e1[3] < e2[3];
}

int main() {
    int N;
    int ans = 0;
    int edge_cnt = 0;
    std::vector<std::vector<int>> positions;
    std::vector<std::vector<int>> edges;
    int root[100000];

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y, z;
        std::vector<int> pos;
        std::cin >> x >> y >> z;
        pos.push_back(i);
        pos.push_back(x);
        pos.push_back(y);
        pos.push_back(z);
        root[i] = i;
        positions.push_back(pos);
    }
    
    std::sort(positions.begin(), positions.end(), cmp_x);
    for (int i = 0; i < N-1; i++) {
        std::vector<int> e;
        int val = std::min(positions[i+1][1] - positions[i][1], std::abs(positions[i+1][2]-positions[i][2]));
        val = std::min(val, std::abs(positions[i+1][3] - positions[i][3]));
        e.push_back(val);
        e.push_back(positions[i][0]);
        e.push_back(positions[i+1][0]);
        edges.push_back(e);
    }

    std::sort(positions.begin(), positions.end(), cmp_y);
    for (int i = 0; i < N-1; i++) {
        std::vector<int> e;
        int val = std::min(positions[i+1][2] - positions[i][2], std::abs(positions[i+1][1]-positions[i][1]));
        val = std::min(val, std::abs(positions[i+1][3] - positions[i][3]));
        e.push_back(val);
        e.push_back(positions[i][0]);
        e.push_back(positions[i+1][0]);
        edges.push_back(e);
    }

    std::sort(positions.begin(), positions.end(), cmp_z);
    for (int i = 0; i < N-1; i++) {
        std::vector<int> e;
        int val = std::min(positions[i+1][3] - positions[i][3], std::abs(positions[i+1][1]-positions[i][1]));
        val = std::min(val, std::abs(positions[i+1][2] - positions[i][2]));
        e.push_back(val);
        e.push_back(positions[i][0]);
        e.push_back(positions[i+1][0]);
        edges.push_back(e);
    }

    std::sort(edges.begin(), edges.end(), cmp_e);

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