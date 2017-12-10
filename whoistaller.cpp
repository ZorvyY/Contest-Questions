#include <iostream>
#include <queue>
using namespace std;

int a[10][10];
int N = 0;

bool bfs (int p, int q) 
{
    queue <int> que;
    que.push(p);
    while (!que.empty()) {
        int temp = que.front();
        for (int i = 0; i < N; i++) {
            if (a[temp][i]) que.push(i);
        }
        if (temp == q) return true;
        que.pop();
    }
    return false;
}


int main(void)
{
    int M;
    cin >> N >> M;
    int a[N][N] = {};
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1]++;
    }

    for (int i = 0; i < N; i++) {
        cout << endl;
        for (int j = 0; j < N; j++) {
            cout << a[i][j] << " ";
        }
    }

    int p, q;
    cin >> p >> q;

    if (bfs(p - 1,q - 1)) {
        cout << "yes";
    } else if (bfs(q - 1,p - 1)) {
        cout << "no";
    } else {
        cout << "unknown";
    }

    return 0;
}
