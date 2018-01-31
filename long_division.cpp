#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    char a[80];
    char b[80];
    char q[80];
    //      a / b

    for (int i = 0; i < N; i++) {
        int c;
        int count = 0;
        for (; (c=getchar())!='\n'; count++) {
            a[count] = c;
        }
        

        for (int count = 0; (c=getchar())!='\n'; count++) {
            b[count] = c;
        }

    
    return 0;
}
