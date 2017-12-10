#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int G[100][100];


void rec (int A, int Z, int listN[], bool visited[], int N) {
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
    rec (next, Z, listN, visited, N);
    return;
}

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[j][i];
        }
    }
    //Unvisited distances list
    int listN[N];
    for (int i = 0; i < N; i++) listN[i] = 500;
    listN[0] = 0;
    bool visited[N];
    for (int i = 0; i < N; i++) {
        visited[i] = false;
    }
    rec(0, (N-1), listN, visited, N);

}
