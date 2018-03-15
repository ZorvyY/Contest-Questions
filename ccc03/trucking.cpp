#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

const int INF = 200000;

inline void scan(int *a){char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

vector <pair<int, int> > list[10011];
bool isdest[10011] = {};
bool vis[10011] = {};
int dist[10011] = {};

int main(void)
{
    ios_base::sync_with_stdio(false);

    int c,r,d;
    cin >> c >> r >> d;
    int x, y, w;
    for (int i = 0; i < r; i++) {
        scan(&x);scan(&y);scan(&w);
        list[x].push_back({w,y});
        list[y].push_back({w,x});
    }
    for (int i = 0; i < d; i++) {
        scan(&x);
        isdest[x] = true;
    }
    
    dist[1] = INF;

    priority_queue<pair<int, int> > q;
    q.push({dist[1],1});
    
    int maxi = 200000;
    while (!q.empty()) {
        int cur = q.top().second;
        q.pop();
        maxi = min(maxi, dist[cur]);
        if (vis[cur]) continue;
        vis[cur] = true;
        if (isdest[cur] == true) {
            --d;
            if (d == 0) break;
        }
        auto adj = list[cur];
        for (int i = 0; i < adj.size(); i++) {
            int target = adj[i].second;
            int cost = adj[i].first;
            if (!vis[target]){
            if (dist[target] < cost) {
                dist[target] = cost;
                q.push({dist[target],target});
            }
            }
        }
    }

    cout << maxi << endl;
    
    return 0;
}
