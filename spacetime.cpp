#include <iostream>
#include <stdio.h>
#include <tuple>

using namespace std;

int R, C, T;

bool G[100][100][10] = {false};

int main(void)
{
    char t;
    int rA, cA, rB, cB;
    cin >> R >> C >> T;
    for (int k = 0; k < T; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                t = getchar();
                if (t == 'X') continue;
                G[i][j][k] = true;
                if (t == 'A') { rA = i; cA = j; }
                if (t == 'B') { rB = i; cB = j; }

            }
        }
    }
    
    return 0;
}

