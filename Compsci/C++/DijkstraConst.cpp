#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int G[9][9] = {0};
bool visited[9] = {false, false, false, false, false, false, false, false, false};
int listN[9] = {0};
int N = 9;

void rec (int A, int Z) {
    visited[A] = true;
    for (int i = 0; i < N; i++) {
        if (G[i][A] != 0) {
            if (G[i][A] + listN[A] < listN[i]) listN[i] = G[i][A] + listN[A];
        }
    }
    int next = 0;
    while (visited[next]) {
        next++;
        if (next == N) {
            cout << listN[Z] << endl;
            return;
        }
    }
    for (int i = 0; i < N; i++) {
        if (listN[i] < listN[next] && visited[i] == false) next = i;
    }
    rec (next, Z);
    return;
}

int main () {
    //fill_n(G, N*N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    fill_n(listN, N*4, 500);
    listN[0] = 0;
    rec(0, 7);

}
