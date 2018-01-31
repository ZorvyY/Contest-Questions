#include <iostream>
#include <stdio.h>

using namespace std;

int a[100000];
int dp[100000] = {};

void fastscan(int &number)
{
    bool negative = false;
    register int c;
 
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

int solve(int i) {
    if (i<0) return 0;
    if (dp[i] > 0 ) return dp[i];
    else {
        int ans = max(solve(i-1), solve(i-2) + a[i]);
        dp[i] = ans;
        return ans;
    }
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        //cin >> a[i];
    }
    cout << solve(n-1);
    return 0;
}
