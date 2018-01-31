#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

inline void fastRead_int(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

int main(void)
{
    int R, C;
    cin >> R >> C;
    int dp[R+1][C+1] = {0};
    memset (dp, 0, (R+1)*(C+1)*sizeof(int));
    bool cat[R+1][C+1] = {0};
    memset (dp, 0, (R+1)*(C+1)*sizeof(bool));
    int K;
    cin >> K;
    int a, b;
    for (int i = 0; i < K; i++) {
        fastRead_int(&a);
        fastRead_int(&b);
        cat[a][b] = true;
    }

    dp[1][1] = 1;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!(cat[i][j])) dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[R][C];
    
    return 0;
}
