#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 999999;

int main(void)
{
    int N = 6;
    int g[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
            if (g[i][j] == 0 && i != j)
                g[i][j] = inf;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
