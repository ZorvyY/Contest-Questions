#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int A[n];
    bool restart;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    do {
        restart = false;
        for (int i = 0; i<n-1; i++) {

            int S;
            if (A[i] > A[i+1]) {
                S = A[i];
                A[i] = A[i+1];
                A[i+1] = S;
                restart = true;
            }
        }
    } while (restart);

    for (int i=0; i<n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
