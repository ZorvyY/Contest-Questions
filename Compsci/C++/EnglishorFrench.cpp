#include <iostream>
#include <string>
using namespace std;


int main() {

// declarations & initializations
int n, a = 0, b = 0;
// inputs
cin >> n;
string lang;
getline(cin, lang);
for (int i = n; i > 0; --i) {
    string temp;
    getline(cin, temp);
    lang = lang + temp;
}
// process

for (int i = 0; i <= lang.length() - 1; i++) {
    if (lang[i] == 't' || lang[i] == 'T') {
        a++;
    }
    else if (lang[i] == 's' || lang[i] == 'S') {
        b++;
    }
}
// output
if (a > b) {
    cout << "English";
} else { cout << "French"; }
    return 0;
}
