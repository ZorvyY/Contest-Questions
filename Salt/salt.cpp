#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    int N, Q;
    map <int, int> X;
    map<int, int> Y;
    map<pair<int, int>, bool> xy;

    cin >> N >> Q;
    
    int first, second;
    for (int i = 0; i < N; i++) {
        cin >> first >> second;
        xy[make_pair(first, second)] = true;
        X[first]++;
        Y[second]++;
    }

    int type;
    for (int i = 0; i < Q; i++) {
        cin >> type;
        if (type - 1) {
            char axis;
            cin >> axis >> second;
            if (axis == 'Y') {
                cout << Y[second] << "\n";
            } else {
                cout << X[second] << "\n";
            }
        } else {
            cin >> first >> second;
            cout << (xy[(make_pair(first, second))] ? "salty" : "bland") << "\n";
        }
    }

    return 0;
}

