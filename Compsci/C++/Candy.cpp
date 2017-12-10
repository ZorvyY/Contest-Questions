#include <iostream>
#include <algorithm>

using namespace std;

/*bool calorie (int LHS[], int RHS[]) {
    return (LHS[1] < RHS[1]);
}*/

int main () {
    int N;
    cin >> N;
    int candy[N][2];
    for (int i = 0; i < N; i++) {
        cin >> candy[i][0] >> candy[i][1];
    }

    int sum1 = 0, sum2 = 0;

    /*The next bit of code finds all the calorie values in the array that have more than 0 bars left.
    It then takes the highest bar and adds it to the sum with a lower value.
    The number of bars is then decreased by one.
    Once all the bars have 0 left, they have all been distributed optimally.*/

    bool restart = true;
    while (restart) {
        restart = false;
        int maxi[2];
        maxi[1] = 0;
        for (int i = 0; i<N; i++) {
            if (candy[i][0] != 0) {
                restart = true;
                if (maxi[1] < candy[i][1]) {
                    maxi[1] = candy[i][1];
                    maxi[0] = i;
                }
            }
        }
        if (sum1 > sum2) {
            sum2 += maxi[1];
        } else {
            sum1 += maxi[1];
        }
        --candy[maxi[0]][0];
        cout << sum1 << " " << sum2 << endl;
    }



    if (sum1 > sum2) {
        cout << (sum1 - sum2);
    } else {
        cout << (sum2 - sum1);
    }




    /*for (int i = 0; i< N; i++) {
        while (candy[i][0] != 0) {
            cout << candy[i][1] << endl;
            --candy[i][0];
        }
    }*/

    return 0;
}
