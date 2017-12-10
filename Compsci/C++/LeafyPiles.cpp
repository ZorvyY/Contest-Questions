#include <iostream>
#include <string>
using namespace std;

int main() {

// declarations & initializations
int N;
cin >> N;
for (int i = 0; i<N; i++) {
    int length;
    cin >> length;
    string A, B;
    cin >> A;
    cin >> B;
    string pile;
    for (int j = length - 1; j >= 0; --j) {
        pile += B[j];
        pile += A[j];
    }
    cout << pile << endl;
}
// inputs

// process

// output

    return 0;
}
