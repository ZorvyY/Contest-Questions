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

    int dist[1002];

    queue<int> pq;
    
    for (int i = 1; i <= N; i++) {
        dist[i] = 20000000;
    }

    dist[1] = 0;

    pq.push(1);

    while(!pq.empty()) {
        int cur = pq.front();
        pq.pop();
        vector<Edge> edges = list[cur];
        for (int i = 0; i < edges.size(); i++) {
            Edge target = edges[i];
            int newDist = dist[cur] + target.cost; 
            if (newDist < dist[target.end]) {
                dist[target.end] = newDist;
                pq.push(target.end);
            }
        }
    }

    printf("%d\n", dist[N]);

    return 0;
}
