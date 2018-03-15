#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int arr[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    bool I = arr[0][0] > arr[1][0];
    bool J = arr[0][0] > arr[0][1];

//    printf("(%d, %d)\n", I, J);

    if (I == false && J == false) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }
    }

    if (I == false && J == true) {
    for (int j = N - 1; j >= 0; j--) {
        for (int i = 0; i < N; i++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }
    }

    if (I == true && J == true) {
    for (int i = N-1; i >= 0; i--) {
        for (int j = N-1; j >= 0; j--) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    }

    if (I == true && J == false) {
    for (int j = 0; j < N; j++) {
        for (int i = N-1; i >= 0; i--) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    }

    return 0;
}
