#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

// Padrão tanto em DFS quanto em BFS;
vector<int> adjList[MAXN];

// Padrão em ambos;
bool visited[MAXN];

// Implementacao DFS;
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adjList[s]) {
        dfs(u);
    }
}

int main() {


    // Implementacao BFS;
    queue<int> q;
    distance[1] = 0;
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int s = q.front(); q.pop();
        for (auto u : adjList[s]) {
            if (visited[u]) continue;
            visited[u];
            distance[u] = distance[s]+1;
            q.push(u);
        }
    }

    return 0;
}
