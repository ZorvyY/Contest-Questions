#include <iostream>
#include <queue>

using namespace std;

int G[100][100];
int N, K;

int paths (int A) {
    int nodes[N];
    int newnodes[N];
    queue <int> Q;
    for (int l = 0; l < N; l++) {
        nodes[l] = 0;
        newnodes[l] = 0;
    }
    newnodes[A] = 1;
    for (int x = 0; x < K; x++) {
        for (int j = 0; j < N; j++) {
            nodes[j] = newnodes[j];
            newnodes[j] = 0;
            if (nodes[j] != 0) {
                Q.push(j);
                //cout << "subtracted 1 from " << j <<endl;
            }
        }
        while (!Q.empty()) {
            int temp = Q.front();
            for (int i = 0; i < N; i++) {
                if (G[i][temp] != 0) {
                    newnodes[i] += nodes[temp];
                    //cout << "added 1 to " << i << "," << temp << "'s adjacent node" << endl;
                }
            }
            nodes[temp] = 0;
            Q.pop();
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        ret += newnodes[i];
    }
    //cout << "accumulated everything for node " << A << ", sum =" << ret << endl;
    return ret;
}

int main () {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += paths(i);
    }
    cout << sum;
    return 0;
}
