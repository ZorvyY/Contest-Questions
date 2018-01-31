#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Point {
    int numPaths = 0;
    vector <int> connections;
};

int main(void)
{
    int N;
    cin >> N;
    Point points[N];

    int start, end;
    while (true) {
        cin >> start >> end;
        if (start + end == 0) break;
        points[start-1].connections.push_back(end - 1);
    }

    points[0].numPaths++;

    for (int i =  0; i < N; i++ ) {
        cout << points[i].numPaths;
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < points[i].connections.size(); j++) {
            cout << "Value of index i: " << i << endl;

            printf("current index: %d\n current connection: %d\n", i, j);
            points[points[i].connections[j]].numPaths += points[i].numPaths;
            cout << "current target node after adding: " << points[points[i].connections[j]].numPaths << "\n\n\n"; 
        }
    }

    cout << points[N-1].numPaths;


    return 0;
}
