#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

inline void scan(int *a){char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

int N;
short arr[1002];

int main() {
    cin >> N;
    int x;
    for (int i = 0; i < N; i++) {
        scan(&x);
        ++arr[x];
    }

    priority_queue<pair<int,int> > pq;
    for (int i = 0; i < 1001; i++) {
        if (arr[i]) {
            pq.push({arr[i], i});
        }
    }

    vector<int> a;

    int freq = pq.top().first;
    a.push_back(pq.top().second);
    pq.pop();

    while (pq.top().first == freq) {
        if (pq.size() == 0) break;
        a.push_back(pq.top().second);
        pq.pop();
    }

    if (a.size() > 1) {
        cout << a[0] - a.back() << endl;
        return 0;
    }

    vector<int> b;
    freq = pq.top().first;
    b.push_back(pq.top().second);
    pq.pop();
    while (pq.top().first == freq) {
        if (pq.size() == 0) break;
        b.push_back(pq.top().second);
        pq.pop();
    }

    printf("%d\n", max(abs(b[0] - a[0]), abs(b.back() - a[0])));

    return 0;
}
