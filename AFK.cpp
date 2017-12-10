#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        char a[N][M];

        pair <int, int> start;
        pair <int, int> end;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'C' or a[i][j] == 'W') {
                    if (a[i][j] == 'C') start = make_pair(i, j);
                    else if (a[i][j] == 'W') end = make_pair(i,j);
                }
            }
        }
        
        queue <pair<int, int> > q;
        q.push(start);
        
        bool visited[N][M] = {};

        while (!q.empty()) {
            pair <int, int> current = q.front();

        }

    }
    return 0;
}
