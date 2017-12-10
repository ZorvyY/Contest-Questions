#include <iostream>
#include <string.h>
using namespace std;

    int A[6][6];
    bool V[6];

int connection (int V) {
    for (int j = 0; j<6; j++) {
        if (A[V][j] == 1 && V[j] == true) {
            V[j] == false;
            return j;
        }
    }
}


int main () {

    int M;
    cin >> M;


    memset (A, 0, 6*6*4);
    memset (V, true, 6*4);


    int i, j;
    for (int n= 0; n<M; n++) {
        cin >> i >> j;
        ++A[i][j];
        ++A[j][i];
    }

    for (i = 0; i<6; i++) {
        for (j = 0; j < 6; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int start;
    cin >> start;
    cout << endl;
    cout << connection(start);

    return 0;
}
