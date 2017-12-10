#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Assignment {
    int due;
    int work;
};

bool sortAssign (Assignment LHS, Assignment RHS) {
    return (LHS.due < RHS.due);
}

int main(){
    int N;
    cin >> N;
    Assignment list[N];
    for (int i = 0; i < N; i++) {
        cin >> list[i].due;
        cin >> list[i].work;
    }
    sort(list, list+N, sortAssign);
    /*
    for (int i = 0; i < N; i++) {
        cout << list[i].due << " " << list[i].work << endl;
    }
    return 0;
    */
    int penalty = 0;
    for (int i = 0; i < N; i++) {
        int due; int work;
        due = list[i].due;
        work = list[i].work;
        if (work - due > 0) {
            penalty += work - due;
            for (int j = i; j < N; j++) {
                list[j].due -= due;
            }
        } else {
            for (int j = i; j < N; j++) {
                list[j].due -= work;
            }
            continue;
        }
    }
    cout << penalty << endl;
}
