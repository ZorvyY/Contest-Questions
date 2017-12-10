#include <iostream>

using namespace std;

int main()
{
    int N, M, E;
    cin >> N >> M >> E;
    int current = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp - current > 2 * M) {
            cout << "Unfair!";
            return 0;
        } else  if (temp - current > M) {
            E--;
            if (E < 0) {
                cout << "Unfair!";
                return 0;
            }
        }
        current = temp;
    }
    cout << "Too easy!";
    return 0;
}
