#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool alpha (string LHS, string RHS) {
    int i = 0;
    while (LHS[i] == RHS[i]) {
        if (i + 1 == LHS.length()) {
            return (true);
        } else if (i + 1 == RHS.length()) {
            return (false);
        }
        i++;
    }
    return (LHS[i] < RHS [i]);
}

int main () {
    int N;
    cin >> N;
    //string listA[N];
    string temp;
    vector <string> listA;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        listA.push_back(temp);
    }
    sort (listA.begin(), listA.end(), alpha);
    for (int i = 0; i < N; i++) {
        cout << listA[i] << endl;
    }

    return 0;
}
