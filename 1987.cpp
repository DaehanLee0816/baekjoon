#include <iostream>
#include <vector>

using namespace std;

static int N, M;

bool is_on_road(vector<char> &prev_path, char map_val) {
    int n = prev_path.size();

    for (int i=0; i < n; i++) {
        if (prev_path[i] == map_val) {
            return true;
        }
    }
    
    return false;
}

void DFS(char (*map)[20], bool (*is_visited)[20], vector<char> &prev_path,
         int col, int x, int y, int &ret) {
             
    if (is_visited[y][x] == true) {
        return;
    }
    if (is_on_road(prev_path, map[y][x])) {
        return;
    }
    
    prev_path.push_back(map[y][x]);
    is_visited[y][x] = true;
    
    if (x < M-1) {
        DFS(map, is_visited, prev_path, col, x+1, y, ret);
    }
    
    if (y < col-1) {
        DFS(map, is_visited, prev_path, col, x, y+1, ret);
    }
    
    if (x != 0) {
        DFS(map, is_visited, prev_path, col, x-1, y, ret);
    }
    
    if (y != 0) {
        DFS(map, is_visited, prev_path, col, x, y-1, ret);
    }
    
    if (prev_path.size() > ret) {
        ret = prev_path.size();
    }
    
    is_visited[y][x] = false;
    prev_path.pop_back();
}

int main()
{
    cin >> N >> M;
    
    char map[N][20];
    bool is_visited[N][20] = {0};
    int ret = 0;
    vector<char> path;
    
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    
    DFS(map, is_visited, path, N, 0, 0, ret);
    
    cout << ret;
    return 0;
    
}