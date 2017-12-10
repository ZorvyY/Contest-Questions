#include <iostream>

using namespace std;

int main () {
    int T;
    cin >> T;
    for (int i= 0; i<T; i++) {
        int N;
        cin >> N;
        char ans = 'Y';
        int maxi;
        int mini;
        int temp;
        cin >> maxi;
        cin >> mini;
        if (maxi < mini) {
            temp = maxi;
            maxi = mini;
            mini = temp;
        }
        for (int j = 0; j<N-2; j++) {
            cin >> temp;
            if (temp == mini - 1) --mini;
            else if (temp == maxi + 1) ++maxi;
            else {
                ans = 'N';
            }
        }
        cout << ans << endl;
    }



    return 0;
}
