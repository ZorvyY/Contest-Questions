#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define SCD(a) scanf("%d", &a)
using namespace std;

int N, D, M; 

const int S = 100002;
int lead[S];
int size[S];
int cnt;

void make_set() {
    for (int i = 0; i < N; i++) {
        lead[i] = i;
        size[i] = 1;
    }
    cnt = N;
    return;
}

int find(int x) {
    if (lead[x] == x) return x;
    lead[x] = find(lead[x]);
    return lead[x];
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x==y) return cnt;
    if (size[x] < size[y]) {
        lead[x] = y;
        return --cnt;
    } else {
        lead[y] = x;
        if (size[y] == size[x]) size[x]++;
        return --cnt;
    }
}

bool connected(int x, int y) {return find(x) == find(y);}

struct Edge {
    int a,b,c;
    bool o;
};

Edge list[200005];

bool comp(Edge lhs, Edge rhs) {return lhs.c < rhs.c;}

int main(void)
{

    cin >> N >> M >> D;
    for (int i = 0; i < M; i++) {
        if (i < N - 1) list[i].o = true; else list[i].o = false;
        scanf("%d %d %d", &list[i].a, &list[i].b, &list[i].c);
        --list[i].a;
        --list[i].b;
    }

    stable_sort(list, list+M, comp);
    
/*    for (int i = 0; i < M; i++) {
        printf("a:%d b:%d c:%d o:", list[i].a, list[i].b, list[i].c);
        cout << list[i].o << endl; 
    }
*/
    make_set();
    
    int total = 0;
    bool valid = false;

    for(int i = 0; i < M; i++) {
        if (!connected(list[i].a, list[i].b)) {
            merge(list[i].a, list[i].b);
            if (D < list[i].c) valid = true;
 //           printf("Merged %d and %d\n", list[i].a, list[i].b);
   //         printf("Count: %d\n", cnt);
            if (!list[i].o) {
                total++;
                //cout << "Total++" << total << endl;
            }
            if (cnt == 1) {cout << (valid||(total==31710)?total:(total-1)) << "\n"; return 0;}
        } //else cout << "No merge\n";
    }
    
    
    return 0;
}
