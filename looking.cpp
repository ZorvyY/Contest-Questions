#include <iostream>
#include <math.h>
#include <stdio.h>
#define ll long long int

using namespace std;

int inside(ll x, ll y, ll zoom) {
    ll o = zoom;
    ll div = 1;
    while (zoom > 1) {
        div *= 5;
        --zoom;
    }
    x /= div;
    y /= div;

    int arr[5][5] = {
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,2,1,1},
        {1,2,0,2,1},
        {1,0,0,0,1}
    };

    int ans = arr[4-y][x];

    if (ans == 2 && o == 1) return 1;

    return ans;
}

bool rec(ll x, ll y, ll zoom) {
    int status = inside(x, y, zoom);
    int o = zoom;

    if (status == 0) return true;
    if (status == 1) return false;

    ll div = 1;
    while (zoom > 1) {
        div *= 5;
        --zoom;
    }
    x %= div;
    y %= div;
    return rec(x, y, o - 1);
}

int main(void)
{
    int N;
    cin >> N;
    for (int i =0; i < N; i++) {
        ll m, x, y;
        cin >> m >> x >> y;
        /*for (int i = 0; i < pow(5, m); i++) {
            for (int j = 0; j < pow(5, m); j++) {
                cout << (rec(i,j,m));
            }
            cout << "\n";
        }*/
        cout << ((rec(x,y,m))?"crystal\n":"empty\n");
    }
    return 0;
}
