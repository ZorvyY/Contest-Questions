#include <iostream>
#include <stdio.h>
#include <functional>
#include <numeric>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int dif[N];
    dif[0] = 0;
    for (int i = 1; i < N; i++) {
        dif[i] = arr[i] - arr[i-1];
    }
    for (int i = 0; i < N; i++) {
        cout << dif[i] << " " ;
    }
    cout << endl;


    return 0;
}
