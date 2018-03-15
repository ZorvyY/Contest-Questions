#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int R, C;

struct Cell {
    bool walk = false;
    int dist = -1;
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

queue < pair<int, int> > q;
bool vis[101][101] = {};

void bfs() {
    while (!q.empty()) {
        int i;
        int j;
        i = q.front().first;
        j = q.front().second;
        q.pop();
        auto cell = arr[i][j];
        if (vis[i][j]) continue;
        vis[i][j] = true;
        if (!arr[i][j].walk) {
            arr[i][j].dist = -1;
            continue;
        }
        if (arr[i][j].type == '.' || arr[i][j].type == 'S') {
            if (!vis[i+1][j]) {
                q.push({i+1, j});
                if (arr[i+1][j].dist == -1)
                arr[i+1][j].dist = (arr[i][j].dist + 1);
            }

            if (!vis[i-1][j]) {
                q.push({i-1, j});
                if (arr[i-1][j].dist == -1)
                arr[i-1][j].dist = arr[i][j].dist + 1;
            }
            
            if (!vis[i][j+1]) {
                q.push({i, j+1});
                if (arr[i][j+1].dist == -1)
                arr[i][j+1].dist = arr[i][j].dist + 1;
            }

            if (!vis[i][j-1]) {
                q.push({i, j-1});
                if (arr[i][j-1].dist == -1)
                arr[i][j-1].dist = arr[i][j].dist + 1;
            }
            continue;
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
                arr[i][j].dist = 0;
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j].type == 'C') {
                camera(i,j);
            }
        }
    }

    /*
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j].walk << " ";
        }
        cout << "\n";
    }
    */

    q.push({start.first, start.second});
    bfs();
    

    /*
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << arr[i][j].dist << "\t";
        }
        cout << "\n";
    }
    */
    

    //cout << "FINAL RESULT\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (arr[i][j].type == '.') {
                cout << arr[i][j].dist << "\n";
            }
        }
    }
    
    return 0;
}
