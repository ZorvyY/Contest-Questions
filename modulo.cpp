#include <iostream>
#include <stdio.h>

using namespace std;

int ar[43] = {};

int main(void)
{
    int a;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a);
        ar[a%42]++;
    }
    int sum = 0;
    for (int i = 0; i < 43; i++) {
        if (ar[i] != 0) {
            sum++;
        }
    }
    printf("%d\n", sum);
    return 0;
}
