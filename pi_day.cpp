#include <iostream>
#include <map>

using namespace std;

map<int, int> mem;


int N; int K;

int count (int n, int k, int m) {
    int key = (n*k - m);
    if (mem.count(key)) {
        return mem[key];
    }
    if (k==1) { 
        return n/(k+1) - m + 1;
    }
    int ret = 0;
    for (int i = m; i <= n / (k + 1); i++) {
        ret += count (n - i, k - 1, i);
    }
    //printf("%d has completed.\n", garbage);
    mem[key] = ret;
    return (ret);
}

int main () {
    cin >> N >> K;
    cout << count (N, K-1, 1);
    return 0;
}
