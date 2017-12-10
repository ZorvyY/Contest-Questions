#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

string A, B;
int carry;

bool alpha (string LHS, string RHS) {
    int i = 0;
    while (LHS[i] == RHS[i]) {
        i++;
    }
    return (LHS[i] < RHS [i]);
}

char adder (char A, char B, int &carry) {
    int Anum = A - '0';
    int Bnum = B - '0';
    char sum = (Anum + Bnum + carry);
    if (sum > 9) {
        sum = sum - 10;
        carry = 1;
    } else {
        carry = 0;
    }
    sum = sum + '0';
    return sum;
}

void complement (string &X) {
    for (int i = 0; i < X.length(); i++) {
        X[i] = '9' - X[i] + '0';
    }
    ++X[0];
    int i = 0;
    while (X[i] == ':') {
        X[i] -= 10;
        ++X[i+1];
        i++;
    }
}

void remove0 (string &X) {
    while (A[A.length() - 1] == '0'){
        A.pop_back();
    }
    return;
}

int main () {
    char c;
    bool comp1 = false, comp2 = false, comp3 = false;
    while (true) {
       c = getchar();
       if (c == '-') {
            comp1 = true;
            continue;
       }
       if (c < '/') break;
       A = c + A;
    }
    while (true) {
       c = getchar();
       if (c == '-') {
            comp2 = true;
            continue;
       }
       if (c < '/') break;
       B = c + B;
    }

    if (comp1 != comp2 && A == B) {
        cout << 0;
        return 0;
    }

    if (comp1 == true && comp2 == true) {
            comp1 = false; comp2 = false; comp3 = true;
    }

    if (A.length() < B.length()) {
        A.swap(B);
        bool temp;
        temp = comp1;
        comp1 = comp2;
        comp2 = temp;
    } else if (alpha (A, B) && A.length() == B.length()) {
        A.swap(B);
        bool temp;
        temp = comp1;
        comp1 = comp2;
        comp2 = temp;
    }

    while (A.length() != B.length()) B += '0';

    if (comp1) complement(A);
    if (comp2) complement(B);

    //cout << A << endl << B << endl;


    //adder.

    for (int i = 0; i < A.length(); i++) {
        A[i] = adder (A[i], B[i], carry);
        if (i == A.length() - 1 && carry == 1) {
            A += '0';
            B += "00";
        }
    }
    //end adder.

    //cout << A << endl;



    if (comp2) {
        if (A.length() < B.length()) --A[A.length() - 1];
        remove0(A);
        //cout << A << endl;
    }
    if (comp1) {
        complement (A);
        //cout << A << endl;
        remove0(A);
        //cout << A << endl;
        A += '-';
    }

    if (comp3 == true) A += '-';

    for (int i = A.length() - 1; i >= 0; i--) {
        cout << A[i];
    }
    cout << endl;
    return 0;
}
