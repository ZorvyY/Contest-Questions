#include <iostream>
#include <string>
using namespace std;

int main() {
string str;
cin >> str;
string ans;
int j = 0;
string monster = "'s.monster";
for (int i = 0; i<str.length(); i++) {
    ans += str[i];
    if (ans[j] == 'n' && ans[j-1] == 'i' &&  ans[j-2] == 'e') {
        ans += "'s.monster";
        j += monster.length();
    }
    j++;
}
cout << ans;


    return 0;
}
