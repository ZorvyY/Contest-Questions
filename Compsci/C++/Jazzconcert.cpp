#include <iostream>

using namespace std;

int main () {
    int N;
    cin >> N;
    int A[N];
    int time = 10;
    int highest = 0, hi2 = 0;
    for (int i = 0; i<N ; i++) {
        cin >> A[i];
        time += A[i];
        if (highest < A[i]) {
                highest = A[i];
                A[i] = 0;
        }
    }
    for (int i = 0; i<N ; i++) {
        if (hi2 < A[i]) hi2 = A[i];
    }
    time += highest;
    time += hi2;
    cout << time << endl;

}
