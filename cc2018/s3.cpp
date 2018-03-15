#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int R, C;

struct Cell {
    bool walk = false;
    int dist = -1;
    int pI, pJ;
    char type;
};

Cell arr[101][101];

void camera(int i, int j) {
    int x = j;
    int y = i;
    while(arr[i][j].type != 'W') {
        if (arr[i][j].type == '.') {
            arr[i][j].walk = false;
        }
        j++;
    }
    i = y;
    j = x;
    while(arr[i][j].type != 'W') {
        if (arr[i][j].type == '.') {
            arr[i][j].walk = false;
        }
        i++;
    }
    i = y;
    j = x;
    while(arr[i][j].type != 'W') {
        if (arr[i][j].type == '.') {
            arr[i][j].walk = false;
        }
        i--;
    }
    i = y;
    j = x;
    while(arr[i][j].type != 'W') {
        if (arr[i][j].type == '.') {
            arr[i][j].walk = false;
        }
        j--;
    }
}

priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > q;
//priority_queue<pair<int, pair<int,int> > > q;
bool vis[101][101] = {};

void bfs() {
    while (!q.empty()) {
        int i;
        int j;
        i = q.top().second.first;
        j = q.top().second.second;
        q.pop();
        auto cell = arr[i][j];
        if (vis[i][j]) continue;
        vis[i][j] = true;
        if (!arr[i][j].walk) continue;
        if (arr[i][j].type == '.' || arr[i][j].type == 'S') {
            arr[i][j].dist = arr[arr[i][j].pI][arr[i][j].pJ].dist + 1;

            q.push({arr[i][j].dist, {i+1, j}});
            arr[i+1][j].pI = i;
            arr[i+1][j].pJ = j;

            q.push({arr[i][j].dist, {i-1, j}});
            arr[i-1][j].pI = i;
            arr[i-1][j].pJ = j;
            
            q.push({arr[i][j].dist, {i, j+1}});
            arr[i][j+1].pI = i;
            arr[i][j+1].pJ = j;

            q.push({arr[i][j].dist, {i, j-1}});
            arr[i][j-1].pI = i;
            arr[i][j-1].pJ = j;
            continue;
        }
        arr[i][j].dist = arr[arr[i][j].pI][arr[i][j].pJ].dist;
        if (arr[i][j].type == 'L') {
            q.push({arr[i][j].dist, {i, j-1}});
            arr[i][j-1].pJ = j;
            arr[i][j-1].pI = i;
        }
        if (arr[i][j].type == 'R') {
            q.push({arr[i][j].dist, {i, j+1}});
            arr[i][j+1].pI = i;
            arr[i][j+1].pJ = j;
        }
        if (arr[i][j].type == 'U') {
            q.push({arr[i][j].dist, {i+1, j}});
            arr[i+1][j].pI = i;
            arr[i+1][j].pJ = j;
        }
        if (arr[i][j].type == 'D') {
            q.push({arr[i][j].dist, {i-1, j}});
            arr[i-1][j].pI = i;
            arr[i-1][j].pJ = j;
        }
    }
}

int main(void)
{
    cin >> R >> C;
    pair <int, int> start;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j].type;
            if (arr[i][j].type == '.' || arr[i][j].type == 'L' ||
                    arr[i][j].type == 'R' || arr[i][j].type == 'U' ||
                    arr[i][j].type == 'D' || arr[i][j].type == 'S') {
                arr[i][j].walk = true;
            }
            if (arr[i][j].type == 'S') {
                start.first = i;
                start.second = j;
            }
            arr[i][j].pI = i;
            arr[i][j].pJ = j;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j].type == 'C') {
                camera(i,j);
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j].walk << " ";
        }
        cout << "\n";
    }

    q.push({0, {start.first, start.second}});
    bfs();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j].dist << "\t";
        }
        cout << "\n";
    }

    //cout << "FINAL RESULT\n";
    /*
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j].type == '.') {
                cout << arr[i][j].dist << "\n";
            }
        }
    }
    */

    
    return 0;
}
