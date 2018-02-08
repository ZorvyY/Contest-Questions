//The Tachyon Trap
#include <iostream>
#include <stdio.h>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int x[10], y[10];

typedef tuple<int, int, int> Eq;

Eq equation(int x1, int y1, int x2, int y2) {
    int A = y2 - y1;
    int B = x1 - x2;
    int C = A*x1 + B*y1;
    return make_tuple(A, B, C);
}

double POI(Eq a, Eq b) {
    int A1 = get<0>(a), A2 = get<0>(b);
    int B1 = get<1>(a), B2 = get<1>(b);
    int C1 = get<2>(a), C2 = get<2>(b);
    int det = A1*B2 - A2*B1;
    if (det == 0) {
        return -1;
    } else {
        double res = (B2*C1-B1*C2)/det;
        return res;
    }
}

bool intersects (double poi, int x1, int x2) {
    return (poi > static_cast<double>(x1) && poi < static_cast<double>(x2));
}

int combinations(vector<int> vec) {
    auto newVec = vec;
    int p = vec.back(); vec.pop_back();
    Eq eq = equation (x[p], y[p], x[vec.back()], y[vec.back()]);
    int x1 = x[p];
    int x2 = x[vec.back()];
    for (int i = 0; i < vec.size()-1; i++) {
        //printf("We're here: \t%d", i);
        Eq temp = equation (x[vec[i]], y[vec[i]], x[vec[i]+1], y[vec[i]+1]);
        //printf("We're here: \t%d", i);
        if (intersects(POI(eq, temp), x1, x2)) {
            return 0;
        }
        //printf("We're here: \t%d", i);
    }
    if (newVec.size() == N) {
        for (int i = 0; i < newVec.size(); i++) {
            cout << newVec[i] << " ";
        } cout << endl;
        return 1;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (std::find(newVec.begin(), newVec.end(), i) == newVec.end()) {
            auto arg = newVec;
            arg.push_back(i);
            sum += combinations(arg);
        }
    }
    return sum;
}


int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    int sum = 0;
    vector<int> newVec = {0};
    /*
    for (int i = 0; i < N; i++) {
        if (find(newVec.begin(), newVec.end(), i) == newVec.end()) {
            auto arg = newVec;
            arg.push_back(i);
            sum += combinations(arg);
        }
    }
    */
//    cout << combinations(newVec) << endl;

    cout << sum << "\n";
    return 0;
}
