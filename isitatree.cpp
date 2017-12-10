#include <iostream>

using namespace std;

int main(void)
{
    int graph[4][4];
    int V = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> graph[i][j];
            V += graph[i][j];
        }
    }

    std::cout << ((3 == V / 2)? "Yes" : "No") << std::endl;

    return 0;
}
