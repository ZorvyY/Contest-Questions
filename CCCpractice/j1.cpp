#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int count = 0;

    int a = N;
    int b = 0;


    if (a > 5) {
        b += a - 5;
        a -= (a - 5);
    }

    while (a >= b) {
        ++count;
        --a; ++b;
    }
    cout << count << endl;
    
    return 0;
}
