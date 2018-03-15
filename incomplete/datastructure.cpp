#include <iostream> 
#include <utility>

using namespace std;


int N, M;
long long ans = 0;
void count (int row, int col, bool counted[]) {
    if (counted[row * N + col]) {
        return;
    }
    counted[row * N + col]++;
    ans++;
    if (row == N - 1) return;
    count (row + 1, col, counted);
    count (row + 1, col + 1, counted);
    return;
}

int main(void)
{
    cin >> N >> M;
    
    bool counted[N * N] = {};

    for (int i = 0; i < M; i++) {
        int row, col;
        cin >> row >> col;
        row--; col--;
        count(row, col, counted);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << counted[i * N + j] << " ";
        }
        cout << endl;
    }

    cout << ans;
    return 0;
}
