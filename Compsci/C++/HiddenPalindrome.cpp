#include <iostream>
#include <string>

using namespace std;

    string str;

int even (int i) {
    int ret = 0;
    int j = i+1;
    while (str[i] == str[j]) {
        ret += 2;
        i--;
        j++;
    }
    return ret;
}

int odd (int i) {
    int ret = 1;
    int j = i+1;
    i--;
    while (str[i] == str[j]) {
        ret += 2;
        i--;
        j++;
    }
    return ret;
}

int main () {
    cin >> str;
    int maxi = 0;
    int tempeven, tempodd;
    for (int i = 0; i<str.length() - 1; i++) {
        tempeven = even(i);
        tempodd = odd(i);
        if (tempeven > maxi) {
            maxi = tempeven;
        }
        if (tempodd > maxi) {
            maxi = tempodd;
        }
    }
    cout << maxi;

    return 0;
}
