#include <iostream>

using namespace std;

bool removeBS (string &str) {
    int countB = 0, countS = 0;
    for (int i = 0; i<str.length(); i++) {
        if (str[i] == 'B' && str[i+1] == 'S') return true;
        if (str[i] == 'B' && str[i+1] == 'N') return true;
        if (str[i] == 'S' && str[i-1] == 'N') return true;
        if (str[i] == 'B') {
            ++countB;
            str.erase(str.begin() + i);
            i--;
        }
        if (str[i] == 'S') {
            ++countS;
            str.erase(str.begin() + i);
            i--;
        }
    }
    if (countB != countS) return true;
    else return false;
}

int main () {
    string str;
    while (true) {
        cin >> str;
        //cout << "passed test 0" << endl;
        if (str == "X") break;
        if (removeBS(str)) {
            cout << "NO" << endl;
            continue;
        }
        //cout << "passed test 1" << endl;
        while (str.length() > 1) {
            if (str[0] == 'A' && str[1] == 'N') str.erase(0, 2); else break;
        }
        if (str == "A") {
            cout << "YES" << endl;
        } else cout << "NO" << endl;

    }

    return 0;
}
