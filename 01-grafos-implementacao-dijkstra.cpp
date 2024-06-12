#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int main() {

    // [n] = node / p/onde / peso;
    vector<pair<int,int>> adj[MAXN];

    // distancia de um node;
    // O primeiro deve ser 0 e o restante infinito.
    vector<int> distance(MAXN, INFINITY);

    // distance / node;
    priority_queue<pair<int, int>>pq;

    // se o node foi process ou nao;
    bool processed[MAXN];

    int x; cin >> x;

    distance[x] = 0;

    // distancia acumulada / node;
    pq.push({0, x});
    // x = 1;

    while (!pq.empty()) {
        // a = node;
        int a = pq.top().second; pq.pop();
        if (processed[a]) continue;
        processed[a] = true;

        // igual BFS, vou falar com cada pair que está na adjList[a]
        for (auto u : adj[a]) {
            // b = para onde / w = peso;
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]) {
                distance[b] = distance[a]+w;
                pq.push({-distance[b],b});
            }
        }

    }
}