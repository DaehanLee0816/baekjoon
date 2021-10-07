#include <iostream>
#include <queue>
#include <vector>

using namespace std;

static int N, M, V;

void DFS(int (*graph)[10000], bool *is_visited, int next_node, vector<int> &path) {
    if (is_visited[next_node-1] == true) {
        return;
    }
    is_visited[next_node-1] = true;
    path.push_back(next_node);
    int i = 0;
    while(graph[next_node-1][i] != 0) {
        DFS(graph, is_visited, graph[next_node-1][i], path);
        i++;
    }
}

void edge_push(int (*graph)[10000], int node, int pushed_val) {
    for (int i=0; i<M; i++) {
        if (graph[node-1][i] == 0) {
            graph[node-1][i] = pushed_val;
            break;
        }
        else if (graph[node-1][i] > pushed_val) {
            int temp = graph[node-1][i];
            graph[node-1][i] = pushed_val;
            for (int j=i+1; j<M+1; j++) {
                if (graph[node-1][j] == 0) {
                    graph[node-1][j] = temp;
                    break;
                }
                int temp_temp;
                temp_temp = graph[node-1][j];
                graph[node-1][j] = temp;
                temp = temp_temp;
            }
            break;
        }
        else {
            continue;
        }
    }
}

void BFS(queue<int> &que, int (*graph)[10000], bool *is_visited, vector<int> &path) {
    int popped_node;
    popped_node = que.front();
    if (is_visited[popped_node-1] == true) {
        que.pop();
        return;
    }
    path.push_back(popped_node);
    que.pop();
    is_visited[popped_node-1] = true;
    for (int i=0; i < M; i++) {
        if (graph[popped_node-1][i] == 0) {
            break;
        }
        
        if (is_visited[graph[popped_node-1][i] - 1] != true) {
            que.push(graph[popped_node-1][i]);
        }
    }
}

int main()
{
    cin >> N >> M >> V;
    int graph[N][10000] = {0};
    bool is_visited[N] = {0};
    int edge[2];

    for (int i=0; i < M; i++) {
        cin >> edge[0] >> edge[1];
        edge_push(graph, edge[0], edge[1]);
        edge_push(graph, edge[1], edge[0]);
    }
    
    vector<int> path;
    DFS(graph, is_visited, V, path);
    
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    path.clear();
    
    
    
    for (int i = 0; i < N; i++) {
        is_visited[i] = false;
    }

    queue<int> que;
    que.push(V);
    
    while(!que.empty()) {
        BFS(que, graph, is_visited, path);
    }
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}