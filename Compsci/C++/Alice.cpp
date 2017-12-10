#include <iostream>

using namespace std;

int main () {
    int G;
    cin >> G;
    int N;
    for (int i = 0; i<G; i++) {
        int mini = 2000000000, maxi = -1;
        cin >> N;
        int temp;
        for (int j=0; j<N; j++) {
            cin >> temp;
            if (maxi < temp) maxi = temp;
            if (mini > temp) mini = temp;
        }
        cout << mini << " " << maxi << endl;
    }

    return 0;
}
