#include <iostream>
#include <string>
using namespace std;

int main () {

    int N, K;
    cin >> N >> K;
    int rooms[N][4];
    memset (rooms, 0, 4*N*4);
    int points = 0;
    for (int i=0; i < N - 1; i++) {
        int Ai, Bi, Mi;
        cin >> Ai >> Bi >> Mi;
        ++rooms[Bi][0];
        ++rooms[Ai][0];
        rooms[Bi][1] = Ai;
        rooms [Bi][2] = Mi;
        points += Mi;
    }
    for (int j=0; j<K; j++) {
        int Ci;
        cin >> Ci;
        rooms[Ci][3] = 1;
    }
    int k = N;
    while (k > 0) {
        if (rooms[k][0] == 1 && rooms[k][3] != 1) {
            --rooms[rooms[k][1]][0];
            --rooms[k][0];
            points -= rooms[k][2];
            k = N;
        }
        k--;
    }

    cout << points;


    return 0;
}
