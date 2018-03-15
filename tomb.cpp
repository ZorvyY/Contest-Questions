#include <stdio.h>
#include <iostream>

using namespace std;

bool a[102][102] = {};
bool vis[102][102] = {};
int R, C;

bool dfs(int i, int j) {
    if (i < 0) return false;
    if (i > R) return false;
    if (j < 0) return false;
    if (j >= C) return false;

    if (!a[i][j]) return false;
    if (vis[i][j]) return false;
    vis[i][j] = true;
    dfs(i+1, j);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i, j-1);

    return true;
}

int main(void)
{
    cin >> R >> C;

    char n;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> n;
            a[i][j] = (n == '.');
        }
    }


    /*
    putchar('\n');

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            putchar((vis[i][j])?'X':'.');
        }
        putchar('\n');
    }
    */

    int sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            sum += dfs(i,j);
        }
    }
    cout << sum << endl;
    
    return 0;
}
