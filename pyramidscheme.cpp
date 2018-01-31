#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int M;
        cin >> M;
        int max = 0;
        vector <string> chain;
        chain.push_back("Home");
        for (int i = 0; i < M; i++) {
            string temp;
            cin >> temp;
            if (chain.size() < 2) {
                chain.push_back(temp);
                continue;
            }
            if (chain[chain.size() - 2] == temp) {
                if (max < chain.size())
                    max = chain.size();
                chain.pop_back();
            } else chain.push_back(temp);
            //if (i == M - 1) 
            //std::cout << temp << std::endl;
        }

        cout << max * 2 - 1;
    }
    
    return 0;
}
