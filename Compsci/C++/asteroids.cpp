#include <iostream>
#include <cmath>
using namespace std;

float distance (int x1, int y1, int x2, int y2) {
    return (sqrt(pow((x2-x1), 2) + pow((y2-y1),2)));
}

float maxdist (int x1, int y1, int x2, int y2, int x3, int y3) {
    float ret = 0;
    float temp;
    temp = distance(x1, y1, x2, y2
    if (temp > ret) ret = temp
}

int main () {
    int N;
    cin >> N;
    cout << sqrt(N);
}
