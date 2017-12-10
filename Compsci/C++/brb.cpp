#include <iostream>

using namespace std;

int main () {
    int N;
    cin >> N;
    string str = "[";
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        str += temp;
        str += ", ";
    }
    str += "]";

    cout << str;

    return 0;
}
