// https://wcipeg.com/problem/ccc99s4
#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int min (int a, int b) {
    if (a < 0) a = 2000000;
    return (a < b ? a : b);
}

int main(void)
{
    int K;
    cin>> K;
    for (int k = 0; k < K; k++) {
    int r, c, pr, pc, kr, kc;
    cin >> r >> c >> pr >> pc >> kr >> kc;
    int counter = 0;
    
    bool vis[r+1][c+1];
    int dist[r+1][c+1];
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            vis[i][j] = false;
            dist[i][j] = r - pr +2;
        }
    }
    
    queue<pair<int, int> > q;
    q.push(make_pair(kr, kc));
    while (counter < r - pr && !q.empty()) {
        int size = q.size();
        for (int x = 0; x < size; x++) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i < 1 || i > r || j < 1 || j > c) continue; 
            if (vis[i][j]) continue;
            dist[i][j] = counter;
            vis[i][j] = true;
            q.push(make_pair(i + 2, j + 1));
            q.push(make_pair(i + 2, j - 1));
            q.push(make_pair(i - 2, j + 1));
            q.push(make_pair(i - 2, j - 1));
            q.push(make_pair(i + 1, j + 2));
            q.push(make_pair(i + 1, j - 2));
            q.push(make_pair(i - 1, j + 2));
            q.push(make_pair(i - 1, j - 2));
        }
        counter++;
    }
/*
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
*/
    int stalemate = -1;
    int win = -1;

    for (int i = 0; i <= r-pr; i++) {
        dist[pr + i][pc] -= i;
        if (i != r-pr) {
            if (dist[pr + i][pc] == 0) win = min(win,i);
        }
        if (dist[pr + i][pc] == -1) stalemate = min(stalemate,i-1);
    }
/*
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
*/

/*    for (int i = r - pr - 1; i >= 1; i++) {
        moves[i] = dist[pr + i][pc];
        moves[i] -= i;
        if (moves[i] == 0) win = i;
        if (moves[i] == 1) stalemate = i;
    }
*/
    if (win > 0) 
        printf("Win in %d knight move(s).", win); 
    else
        if (stalemate > 0) 
            printf("Stalemate in %d knight move(s).", stalemate);
        else
            printf("Loss in %d knight move(s)", r - pr - 1);
    cout << "\n";
    }

    return 0;
}
