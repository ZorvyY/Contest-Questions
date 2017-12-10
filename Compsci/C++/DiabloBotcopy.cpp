#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> words;

string lowercase (string str) {
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] += 32;
        }
    }
    return str;
}

void wordify (string A) {
    while (words.size() != 0) words.pop_back();
    //cout << "HOLYYY SHIT BROOO" << endl;
    while (A.length() != 0) {
        string temp;
        while (A[0] != ' ') {
            temp += A[0];
            A.erase (A.begin());
            //cout << A << endl;
            if (A.length() == 0) break;
        }
        if (A.length() != 0) A.erase (A.begin());
        words.push_back(temp);
        //cout << words.size() - 1 << endl;
    }
    return;
}

bool isNormal () {
    return (lowercase(words[0]) == "damaged");
}

bool isMagic () {
    if (words.size() > 4 || words.size() < 2) return false;
    if (words.size() > 2) {
        return (lowercase(words[words.size() - 2]) == "of");
    }
    return true;
}

bool isSet () {
    string temp;
    temp = words[0];
    if (temp.length() > 2) return (temp [temp.length() - 2] == '\'' &&  (temp [temp.length() - 1] == 's' || temp [temp.length() - 1] == 'S'));
    else return false;
}

bool isRare () {
    return (words.size() == 2);
}



int main () {
    int N;
    cin >> N;
    cin.ignore();
    string str;
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        wordify(str);
        if (isSet()) {
            cout << "Set" << endl; continue;
        }

        if (isNormal()) {
            cout << "Normal" << endl; continue;
        }

        if (isMagic()) {
            if (isRare()) {
                cout << "Not sure, take anyways" << endl; continue;
            } else {
                cout << "Magic" << endl;
                continue;
            }
        } else if (isRare()) {
            cout << "Rare" << endl;
            continue;
        } else {
            cout << "Normal" << endl;
        }
    }


    return 0;
}
