#include <iostream>

using namespace std;

void build (string start, int o0, int l1) {
    if (o0 == 0 && l1 == 0) {
        cout << start << endl;
        return;
    }
    if (l1 != 0) {
        build(start + '1', o0, l1-1);
    }
    if (o0 != 0) {
        build(start + '0', o0-1, l1);
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    int n, k;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n >> k;
        cout << "The bit patterns are\n";
        build(string(), n-k, k);
        cout << "\n";
    }
    return 0;
}
