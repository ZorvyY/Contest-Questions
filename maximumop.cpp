#include <iostream>
#include <stdio.h>  

using namespace std;

int main(void)
{
    int a = 1;
    int b = 2;
    a = a >?: b;
    cout << a << endl;
    return 0;
}
