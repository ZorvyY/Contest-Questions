#include <iostream>

using namespace std;

int main () {

int N;
cin >> N;
string play1;
for (int i=0; i<N; i++) {
    cin >> play1;
    if (play1 == "Foxen") {
        break;
    }
    if (play1[0] == 'R') {
        cout << "Paper" << endl;
    } else if (play1[0] == 'P') {
        cout << "Scissors" << endl;
    } else if (play1[0] == 'S') {
        cout << "Rock"<< endl;
    } else {
        cout << "Foxen"<< endl;
    }
}







    return 0;
}
