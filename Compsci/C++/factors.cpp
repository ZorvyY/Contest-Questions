#include <iostream>
using namespace std;


int main() {

// declarations & initializations
int n;

// inputs
cin >> n;

// process
for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
        cout << n / i;
    }
}
// output
    return 0;
}
