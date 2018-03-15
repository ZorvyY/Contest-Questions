#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int a[N], b[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = a[i];
        if (i == 0) continue;
        A[i] += A[i-1];
    }
    int B[N];
    for (int i = 0; i < N; i++) {
        B[i] = b[i];
        if (i == 0) continue;
        B[i] += B[i-1];
    }
    int idx = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] == B[i]) idx = i;
    }

    /*
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    } cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << b[i] << " ";
    } cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    } cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    } cout << "\n";
    */

    
    cout << idx + 1 << endl;

    return 0;
}
