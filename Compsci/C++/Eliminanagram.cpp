#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main () {
    string str1, str2;
    cin >> str1 >> str2;
    string temp;
    if (str1.length() < str2.length()) {
        str1.swap (str2);
    }
    string ans = "Yes";
    int A[26];
    memset (A, 0, 26*4);
    for (int i = 0; i<str1.length(); i++) {
        ++A[str1[i] - 'a'];
    }
    for (int i = 0; i<str2.length(); i++) {
        ++A[str2[i] - 'a'];
    }
    for (int i = 0; i<26; i++) {
        if (A[i] % 2 != 0) {
            ans = "No";
            break;
        }
    }


    cout << ans;

    return 0;
}
