#include <iostream>
#include <string.h>

using namespace std;

int main () {
    int N, D;
    cin >> N >> D;
    string room;
    cin >> room;

    int counter = 0;

    int i = 0;

    while (i<N) {
        while (room[i] == '.') ++i;
        cout << i;
        ++counter;
        if (i>=N) break;

        i += D;

        while (room[i] == '#') --i;
        while (room[i] == '.') ++i;
        cout << i;
        if (i>=N) break;

        i+= D;
        while (room[i] == '#') --i;
        while (room[i] == '.') ++i;

        cout <<i;

        while (room[i] == '#') {
            ++i;
            if (i>=N) break;
        }
    }


    cout << counter;
}
