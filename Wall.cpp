#include <iostream>
#include <string.h>

using namespace std;

int main () {
    int N; int K;
    cin >> N >> K;
    int wall[N];
    memset (wall, 0, N*4);
    int op; int left; int right; int height;
    for (int i = 0; i < K; i++) {
        cin >> op >> left >> right >> height;
        if (op == 1) {
            for (int j = left; j <= right; j++) {
                if (wall[j] < height) {
                    wall[j] = height;
                }
            }
        } 
        if (op == 1) {
            for (int j = left; j <= right; j++) {
                if (wall[j] > height) {
                    wall[j] = height;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << wall[i] << endl;
    }
    return 0;
}
