#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int Q, M;
int arr[101] = {};
string names[101];
int dp[101] = {};
int past[101] = {};

int time(int q) {
    if (q <= 0) return 0;
    if (dp[q]) return dp[q];
    vector<int> sols;
    for (int i = 1; i <= M; i++) {
        if (q-i < 0) {
            break;
        }
        sols.push_back( *max_element(arr+q-i, arr+q) + time(q - i));
    }
    int idx = min_element(sols.begin(), sols.end()) - sols.begin();
    past[q] = q-idx-1;
    dp[q] = sols[idx];
    return dp[q];
}

int main(void)
{
    cin >> M >> Q;
    string name;
    for (int i = 0; i < Q; i++) {
        cin >> names[i];
        cin >> arr[i];
    }
    cout << "Total Time: " << time(Q) << endl;


    bool groups[101] = {};

    int j = Q; 

    while (j > 0) {
        groups[j] = true;
        j = past[j];
    }

    /*
    for (int i = 1; i <= Q; i++) {
        cout << (groups[i]?"1":"0") << " ";
    }
    */
    
    for (int i = 0; i < Q; i++) {
        cout << names[i] << " ";
        if (groups[i + 1]) {
            cout << "\n";
        }
    }


    //cout << time(Q) << endl;

    
    return 0;
}
