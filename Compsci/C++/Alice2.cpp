#include <iostream>
#include <string>

using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++) {
        string str;
        if (i == 0) getline (cin.ignore(), str);
        else getline (cin, str);
        int counter = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j-1] == '<' && str[j] == '3') ++counter;
        }

        cout << "<3";
        for (int j = 0; j < counter; j++) cout << " <3";
        cout << endl;
    }

    return 0;
}
