//https://wcipeg.com/problem/dp1p2

#include <iostream>
#include <stdio.h>
#include <numeric>

using namespace std;

int dp[1001][1001] = {};
int sum[1001][1001] = {};

int coins[1001] = {};

int total(int l, int r) {
    int init = 0;
    if (sum[l][r]) return sum[l][r];
    sum [l][r] = accumulate(coins+l, coins+r+1, init);
    return sum[l][r];
}

int solve(int l, int r) {
    if (l == r) {
        dp[l][r] = coins[r];
        return dp[l][r];
    }
    if (dp[l][r]) return dp[l][r];
    dp[l][r] = max(coins[l] + total(l+1, r) - solve(l+1, r), coins[r] + total(l, r-1) - solve(l,r-1));
    return dp[l][r];
}


int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", coins+i);
    }

    cout << solve(0, N-1) << endl;
    
    return 0;
}
