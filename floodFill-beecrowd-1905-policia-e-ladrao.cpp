// 07/06/2024
// beecrowd | 1905 - Polícia e Ladrão
// usei o floodFill que aprendi com o ponas com algumas mudancas

#include <bits/stdc++.h>

using namespace std;

int adj[5][5];
bool flag = false;


bool verify(int i, int j) {
    if (i >= 0 && i <= 5-1 && j >= 0 && j <= 5-1) {
        return true;
    }
    return false;
}

void back(int i, int j) {
    bool ver = verify(i, j);
    if (!ver) return;
    adj[i][j] = 2;
    if (flag) return;

    if (i == 4 && j == 4) flag = true;

    if (adj[i+1][j] == 0) {
        back(i+1, j);
    }

    if (adj[i-1][j] == 0) {
        back(i-1, j);
    }

    if (adj[i][j+1] == 0) {
        back(i, j+1);
    }


    if (adj[i][j-1] == 0) {
        back(i, j-1);
    }
}

int main() {
int t; cin >> t;
    while (t--) {
        for (int i = 0; i<5; ++i)
            for (int j = 0; j <5; ++j)
                cin >> adj[i][j];

        if (adj[0][0] == 1){ cout << "ROBBERS\n"; flag = false; continue;}
        if (adj[4][4] == 1){ cout << "ROBBERS\n"; flag = false; continue;}
        back(0, 0);
        if (flag) {cout << "COPS\n";}
        else cout << "ROBBERS\n";
        flag = false;
    }
}

