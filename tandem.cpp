#include <iostream>
#include <algorithm>
using namespace std;

bool comp (int a, int b) {
    return (a>b);
}

int main () {

    int type;
    int N;

    cin >> type >> N;
    int a[N];
    int b[N];

    for (int i = 0; i < N; i++) {
       cin >> a[i]; 
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    sort(a, a+N);
    if (type - 1) {
        sort(b, b+N, comp);
    } else {
        sort(b, b+N);
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        ret += max(a[i],b[i]);
    }

    cout << ret;

    return 0;

}
