// 06/06/2024
// Precisava encontrar um cycle, aprendi nesse artigo: https://cp-algorithms.com/graph/finding-cycle.html

#include <bits/stdc++.h>
using namespace std;

map<int, vector<int> > adjList;
map<int, int> color;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adjList[v]) {
        if (color[u] == 0) {
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}


int main() {
    int t; cin >> t;
    for (int o = 0; o < t; o++) {
        adjList.clear();
        color.clear();
        queue<int>q;
        int n, m; cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int a,b; cin >> a >> b;
            adjList[a].push_back(b);
            q.push(a);
        }


        bool flag = false;
        while (!flag && !q.empty()) {
            int p = q.front(); q.pop();
            if (!color[p]) {flag = dfs(p);}
        }

        if (flag) cout << "SIM\n";
        else cout << "NAO\n";
    }
}