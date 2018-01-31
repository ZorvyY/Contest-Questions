#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

inline void scan(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

int N, M;

struct Edge {
    int end, cost;
    bool operator<(const Edge &a) const {
        return cost < a.cost;
    }
};

vector<Edge> list[1002];

int main(void)
{
    scan(&N); scan(&M); 

    int a,b,c;
    for (int i = 0; i < M; i++) {
        scan(&a); scan(&b); scan(&c);
        list[a].push_back({b,c});
    }

    priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    
    bool vis[2002] = {};
    int dist[2002] = {};
    for (int i = 1; i <= N; i++) {
        dist[i] = 20000000;
        vis[i] = false;
    }

    pq.push({0,1});

    while(!pq.empty()) {
        int cur = pq.top().second; int cost = pq.top().first;
        pq.pop();
        vis[cur] = true;
        vector<Edge> edges = list[cur];
        for (int i = 0; i < edges.size(); i++) {
            Edge target = edges[i];
            if (!vis[target.end]) {
                int newDist = cost + target.cost; 
                dist[target.end] = min(newDist, dist[target.end]);
                pq.push({dist[target.end], target.end});
            }
        }
    }

    printf("%d\n", dist[N]);

    return 0;
}
