// https://www.spoj.com/problems/AKBAR/
// AKBAR - Akbar , The great - 31/05/2024
// não consegui.
#include <bits/stdc++.h>
using namespace std;


const int N = (int) 1e6;
vector<int> adj[N+1];
int visited[N+1];
vector<pair<int, int>> soldiers;

void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool bfs() {
    queue<pair<int,int>>q;
    int sz = (int) soldiers.size();
    for (int i = 0; i < sz; i++) {
        // colocando a city e strength na fila e visitando a cidade;
        q.push({soldiers[i].first, soldiers[i].second});
        visited[soldiers[i].first] = soldiers[i].first;
    }


    while (!q.empty()) {
        int city = q.front().first;
        int strength = q.front().second;
        q.pop();

        if (strength <= 0) {
            // Se a forca for menor que 0 nem adianta aplicar um bfs, já que o soldado vai permanecer na cidade;
            continue;
        }

        for (auto u : adj[city]) {
            if (!visited[u]) {
                // o meu maior erro foi nesse visited[city]
                visited[u] = visited[city];
                q.push({u, strength-1});
            } else {
                if (visited[u] == visited[city]) {
                    continue;
                }
                assert(visited[city] != visited[u]);
                return false;
            }

            // 2 -> 2;
            // 3 -> 2;
        }
    }
    return true;
}

void reset(int n) {
    soldiers.clear();
    for (int i = 1; i <=n;i++) {
        visited[i] = 0;
        adj[i].clear();
    }
}



int main() {
    int t; cin >> t;
    while (t--) {
        int n, r, m; cin >> n >> r >> m;

        while(r--) {
            int a, b; cin >> a >> b;
            addEdge(a, b);
        }

        while(m--) {
            int a, b; cin >> a >> b;
            soldiers.push_back({a, b});
        }

        bool flag = bfs();

        if (!flag) {
            cout << "No\n";
        } else {
            bool ans = true;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    ans = false;
                    break;
                }
            }
            if (ans) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
        reset(n);
    }
    return 0;
}
