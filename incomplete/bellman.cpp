#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

inline void scan(int *a){char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

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
    
    for (int i = 1; i <= N; i++) {
        dist[i] = 20000000;
    }

    dist[1] = 0;

    //pq.push(1);

    for (int j = 0; j < N-1; j++) {
        for (int x = 1; x <=N; x++) {
            int cur = x;
            //pq.pop();
            vector<Edge> edges = list[cur];
            for (int i = 0; i < edges.size(); i++) {
                Edge target = edges[i];
                int newDist = dist[cur] + target.cost; 
                if (newDist < dist[target.end]) {
                    dist[target.end] = newDist;
                    //pq.push(target.end);
                }
            }
        }
    }

    printf("%d\n", dist[N]);

    return 0;
}
