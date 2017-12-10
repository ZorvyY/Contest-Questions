#include <iostream>

using namespace std;

int turnamount = 0;

float A[100];

void turn () {
    ++turnamount;
    int num;
    cout << "enter number of players in mission" << endl;
    cin >> num;
    int B[num];
    cout << "enter players in mission" << endl;
    for (int i = 0; i < num; i++) cin >> B[i];
    int cardcomp = 0;
    cout << "enter card composition (0 for black, 1 for red)" << endl;
    int temp;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        cardcomp += temp;
    }
    cout << "(24)" << endl;
    cout << "relative weight = " << turnamount << endl;
    float cardratio = (float)cardcomp / (float)num;
    cout << "card ratio = " << cardratio << endl;

    for (int i = 0; i < num; i++) {
        A[B[i]] = (A[B[i]]*(float)turnamount + cardratio) / (float)(turnamount + 1);
    }
    return;
}

bool newturn () {
    cout << "new turn?" << endl;
    int n;
    cin >> n;
    return (n);
}

void recalculate(int N) {
    float divisor = 0;
    for (int i = 0; i < N; i++) {
        divisor += A[i];
    }
    for (int i = 0; i < N; i++) {
        A[i] /= divisor;
    }
    return;
}

int main () {
    int N = 7;
    for (int i = 0; i < N; i++) {
        A[i] = (float)1/(float)N;
    }
    for (int i = 0; i < N; i++) cout << i << "   " << A[i] << endl;
    while (newturn()) {
        turn();
        recalculate(N);
        for (int i = 0; i < N; i++) cout << i << "   " << A[i] << endl;
    }



    return 0;
}
