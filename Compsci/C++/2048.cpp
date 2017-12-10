#include <iostream>

using namespace std;

int main () {
    for (int i=0; i<5; i++) {

        int n;
        int sum = 0;
        for (int j = 0; j<16; j++) {
            cin >> n;
            sum += n;
        }
        int ans = 1;
        while (sum - ans*2 > 0) ans *= 2;

        cout << ans << endl;
    }
    return 0;
}
