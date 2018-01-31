#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std; 

inline void fastRead_int(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

vector<int> list[40005];
vector<int> path;
vector<int> path2;
bool vis[40005] = {};
int N;

bool dfsRev (int a) {
    if (vis[a]) return 0;
    if (a == N) return 1;
    vis[a] = true;
    vector<int> vec = list[a];
    int total = 0;
    for (int i = vec.size()-1; i >= 0; i--) {
        if (dfsRev(vec[i])) {
            path2.push_back(a);
            return true;
        }
    }
    return false;
}

bool dfs (int a) {
    if (vis[a]) return 0;
    if (a == N) return 1;
    vis[a] = true;
    vector<int> vec = list[a];
    int total = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (dfs(vec[i])) {
            path.push_back(a);
            return true;
        }
    }
    return false;
}

int main(void)
{
    int M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        fastRead_int(&a);
        fastRead_int(&b);
        list[a].push_back(b);
        list[b].push_back(a);
    }

    bool exists;

    if (dfs(1)) {
        memset(vis, 0, sizeof(bool) * 40005);
        dfsRev(1);
        printf((path==path2)?"No\n":"Yes\n");
    } else cout << "No\n";

    
    return 0;
}
