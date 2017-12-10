#include <iostream>
#include <queue>

using namespace std;

int G[100][100];
int N;

bool loop (int A, int Z, bool listN[]) {
    queue <int> Q;
    Q.push(A);
    while(!Q.empty()) {
        A = Q.front();
        Q.pop();
        for (int i = 0; i < N; i++) {
            if (G[i][A] != 0 && listN[i] == false) {
                Q.push(i);
                listN[i] = true;
            }
        }
    }
    if (listN[Z]) return true;
    return false;
}

int main () {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }
    bool listN[N];
    int loopcount = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) listN[i] = false;
        if (loop(j, j, listN)) ++loopcount;
    }
    cout << loopcount << endl;
    if (loopcount == 0) cout << "YES"; else cout << "NO";
    return 0;
}
