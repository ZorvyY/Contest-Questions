#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> words;

void wordify (string A) {
    while (words.size() != 0) words.pop_back();
    while (A.length() != 0) {
        string temp;
        while (A[0] != ' ') {
            temp += A[0];
            A.erase (A.begin());
        }
        A.erase (A.begin());
        words.push_back(temp);
    }
    return;
}

bool isNormal () {
    return (words[0] == "Damaged" || words[0] == "damaged");
}

bool isMagic () {
    if (words.size() > 4 || words.size() < 2) return false;
    if (words.size() > 2) {
        return ((words[words.size() - 2] == "of" || words[words.size() - 2] == "Of") || (words[words.size() - 2] == "oF" || words[words.size() - 2] == "OF"));
    }
    return true;
}

bool isSet () {
    string temp;
    temp = words[0];
    return (temp [temp.length() - 2] == '\'' &&  temp [temp.length() - 1] == 's');
}

bool isRare () {
    return (words.size() == 2);
}



int main () {
    int N;
    cin >> N;
    string str;
    for (int i = 0; i < N; i++) {
        getline(cin, str);
        wordify(str);
        if (isSet()) cout << "Set" << endl; continue;
        if (isNormal()) cout << "Normal" << endl; continue;
        if (isMagic()) {
            if (isRare()) {cout << "Not sure, take anyways" << endl; continue;}
            else {
                cout << "Magic" << endl;
                continue;
            }
        } else if (isRare()) {cout << "Rare" << endl; continue;}
        else {cout << "Normal" << endl;}
    }


    return 0;
}
