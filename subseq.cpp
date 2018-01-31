#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define SCD(a) scanf("%d", &a)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(n=getchar_unlocked()); x=(x<<3)+(x<<1)+n-'0');} while(0); char n; 

using namespace std;

int a[100005]={};
int dp[100005]={};

int solve(int i) {
    if (i==0) return 0;
    int res[i];
    if (dp[i]!=-1) {
        return dp[i];
    } else {
        for(int j = 0; j < i; j++) {
            res[j]=(a[i]>a[j])?solve(j):-1;
        }
        int ans = *max_element(res,res+i) + 1;
        dp[i]=ans;
        return ans;
    }
}
int main(void)
{
    int n;
    MEM(dp, -1);
    SCD(n);
    for (int i = 1; i <= n; i++) {
        scan(a[i]);
    }
    a[n+1]=9999999;
    cout << solve(n+1)-1 << endl;

    return 0;
}
