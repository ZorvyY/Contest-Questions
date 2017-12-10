#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int main () {
    int T;
    cin >> T;
    for (int i = 0; i<T; i++) {
        stack <int> branch;
        stack <int> mountain;
        int lake = 0;
        int N;
        cin >> N;

        branch.push(N + 1);
        mountain.push(N + 2);
        char ans = 'N';
        int temp;
        for (int j = 0; j<N; j++) {
            cin >> temp;
            mountain.push(temp);
        }
        while (true) {
            if (mountain.size() == 0 && branch.size() == 0) {
                ans = 'Y';
                break;
            }
            if (mountain.top() == lake + 1) {
                ++lake;
                mountain.pop();
                //cout << lake << " fell in lake" <<endl;
            } else if (branch.top() > mountain.top()) {
                branch.push(mountain.top());
                mountain.pop();
                //cout << branch.top() << " moved to branch"<< endl;
            } else if (branch.top() == lake + 1) {
                ++lake;
                branch.pop();
                //cout << lake << " unloaded from branch" << endl;
            } else break;
        }

        cout << ans << endl;
    }
}
