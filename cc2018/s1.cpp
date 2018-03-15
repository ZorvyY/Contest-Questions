#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    /*
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    */


    double mid[N-1];
    for (int i = 0; i < N-1; i++) {
        mid[i] = (static_cast<double>(arr[i+1] + arr[i]))/2;
    }
    /*
    for (int i = 0; i < N-1; i++) {
        cout << mid[i] << " ";
    }cout << endl;
    */

    double dif[N-1];
    for (int i = 0; i < N-2; i++) {
        dif[i] = mid[i+1] - mid[i];
    }
    /*
    for (int i = 0; i < N-2; i++) {
        cout << dif[i] << " ";
    }cout << endl;
    */

    printf("%0.1f\n", *min_element(dif, dif + N - 2));
    
    return 0;
}
