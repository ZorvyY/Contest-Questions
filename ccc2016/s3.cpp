#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

inline void scan(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

using namespace std;

int N, M;

bool vis[100005] = {};
bool pho[100005] = {};

vector<int> list[100005];

int furthest, maxdist = 0;

bool dfs(int a, int dist) {
    vis[a] = true;
    bool needed = false;
    if (pho[a]) needed = true;
    auto adj = list[a];
    for (int i = 0; i < list[a].size(); i++) {
        int node = list[a][i];
        if (vis[node]) continue;
        if (dfs(node, dist + 1)) needed = true;
        else {
            list[a].erase(list[a].begin() + i);
            --i;
            //remove(list[node].begin(), list[node].end(), a);
            --N;
            //May be able to remove above line
        }
    }

    if (needed && (dist > maxdist)) {
        maxdist = dist;
        furthest = a;
    }
    
    return needed;
}


int main(void)
{
    cin >> N >> M;
    int a, b;
    int c;
    int pho1;
    for (int i = 0; i < M; i++) {
        scan(&c);
        pho[c] = true;
        pho1 = c;
    }
    for (int i = 0; i < N-1; i++) {
        scan(&a); scan(&b);
        list[a].push_back(b);
        list[b].push_back(a);
    }


    dfs(pho1, 0);
    
    for (int i = 0; i < 100001; i++) {vis[i]=false;}

    dfs(furthest, 0);

    cout << (N-1)*2 - maxdist << endl;

    return 0;
}
