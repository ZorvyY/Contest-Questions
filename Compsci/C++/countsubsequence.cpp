#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main () {
    string str;
    cin >> str;
    str = '0' + str;
    float arr[str.length()];
    int recent[26] = {0};
    arr[0] = 1;
    for (int i = 1; i < str.length(); i++) {
        arr[i] = arr[i-1]*2;
        if (recent[str[i] - 'a'] != 0) arr[i] -= arr[recent[str[i] - 'a'] - 1];
        if (arr[i] > 10){
            for (int j = 0; j <= i; j++) arr[j] /= 2;
        }
        recent[str[i]-'a'] = i;
    }
    cout << ((arr[str.length() - 1] - arr[0]) % 10007);
    return 0;
}
