#include <iostream>
#include <cstdlib>

using namespace std;


int main () {
    int N;
    cin >> N;
    int A[N][N];
    bool check;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 0;
        }
    }

    int temp;
    for (int i = 0; i < N; i++) {
        do {
            temp = rand() % N;
        } while (temp == i);
        A[i][temp] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < N; i++) {
        int it;
        it = i;
        for (int c = 0; c < N*2; c++) {
            cout << it << ", ";
            for (int j = 0; j < N; j++) {
                if (A[it][j] == 1) {
                    it = j;
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
