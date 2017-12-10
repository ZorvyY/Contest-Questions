#include <iostream>
using namespace std;

int main() {
// declarations & initializations
    int num;
    int a;
    a = 0;
    cin >> num;
// process
    while (num != 1) {
        if (num % 2 == 1) {
            num = num*3 + 1;
        }
        else {
            num /= 2;
        }
        a ++ ;
    }
// output
    cout << a;

    return 0;
}
