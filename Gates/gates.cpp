#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main () {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int G, P;
    cin >> G >> P;
    
    std::vector<int> vec;

    int temp;
    bool end = false;
    for (int i = 0; i < P; i++) {
        std::cin >> temp;
        int position = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();
        if (position >= vec.size()) {
            vec.push_back(temp);
            continue;
        }
        while (vec[position] == temp) {
            position--;
            temp--;
            if (position == -1 && temp == 0) {
                end = true;
                break;
            }
        }
        if (end) break;

        vec.insert(vec.begin() + position + 1, temp);
        /*
        std::cout << "For loop i at: " << i << std::endl;
        for (int j = 0; j < vec.size(); j++) {
            std::cout << vec[j] << " ";
        }
        */

    }

    std::cout << vec.size() << std::endl;

    return 0;
}
