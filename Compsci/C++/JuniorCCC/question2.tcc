#include <iostream>
#include <string>
using namespace std;

int main() {
string str;
cin >> str;
string ans;
int j = 0;
for (int i = 0; i<str.length(); i++) {
    ans += str[i];
    j++;
    if (ans[j] == 'n' && ans[j-1] == 'i' &&  ans[j-2] == 'e') {
        ans += "'s.monster";
        j += 10;
    }
}
cout << ans;


    return 0;
}
