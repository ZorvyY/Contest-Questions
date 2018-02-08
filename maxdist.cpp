#include <iostream>
#include <stdio.h>

inline void scan(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {

    int N;
    cin >> N;
    int X[N]; 
    int Y[N];
    for (int i = 0; i < N; i++) {
        scan(&X[i]);
    }
    for (int i = 0; i < N; i++) {
        scan(&Y[i]);
    }
    
    int i = N - 2;
    int j = N - 1;

    int maxdiff[N] = {};

    while (true) {
        if (i < 0 || j < 0) break;
        if (Y[j] >= X[i]) { 
            maxdiff[j] = j - i;
            i--;
            continue;
        }
        if (Y[j] < X[i]) {
            j--;
            continue;
        }
    }

    int maxi = 0;
    for (int i = 0; i < N; i++) 
        maxi = max(maxdiff[i], maxi);

    printf("The maximum distance is %d\n", maxi);


    }
    return 0;
}
