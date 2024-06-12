// 07/06/2024
// beecrowd | 1907 - Coloração de Cenários de Jogos
// Uma implementacao diferente de dfs com pilha;

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1050

char adj[MAXN][MAXN];
int x, y;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int n, int m) {

    stack<pair<int, int>> pilha;
    pilha.push({n,m});

    while (!pilha.empty()) {
        auto [p, q] = pilha.top();
        pilha.pop();

        if (p < 0 || p >= x || q < 0 || q >= y) continue;

        if (adj[p][q] == 'o') continue;

        adj[p][q] = 'o';

        for (int i = 0; i < 4; ++i) {
            int nn = p + dx[i];
            int nm = q + dy[i];
            pilha.push({nn, nm});
        }
    }

}


int main() {
    cin >> x >> y;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> adj[i][j];
            }
    }

    int k = 0;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            if (adj[i][j] == '.') {
                k++;
                dfs(i, j);
            }
        }
    }

    cout << k << endl;
    return 0;
}
