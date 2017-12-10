#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
int cases;
cin >> cases;


for (int A = 0; A<cases; A++) {
    int N, C, T;
    cin >> N >> C >> T;
    vector <int> G;
    int temp;
    cin >> temp;
    G.push_back(temp);
    for (int i=1; i<N; i++) {
        cin >> temp;
        if (temp > G[0]) {
            G.push_back(temp);
        }
    }
    sort (G.begin(), G.end());

    /*cout << endl;
    for (int i = 0; i < G.size(); i++) {
        cout << G[i] << " ";
    }
    cout << endl; */

    int i = 0, j = 0, counter = 0;
    while (true) {
        //cout << "HELP PLEASE" << endl;;
        if (G[i] == G.size() - 1) {
            //cout << "breaking because i = " << i << endl;
            break;
        }
        while (G[i] + C >= G[j+1]) {
            j++;
            if (j == G.size() - 1) {
                //cout << "breaking because j = " << j << endl;
                i = j;
                ++counter;
                break;
            }

            //cout << j << " <-- increment index "<< endl << endl;
        }
        if (i == j) {
            //cout << "(i == j), i = " << i << endl << endl;
            break;
        }
        i = j;
        //cout << i << endl;
        ++counter;
    }
    //cout << "highest value: "<< G[i] << endl << "time: " << counter*T << endl;
    cout << G[i] <<" " << counter*T << endl;




}

    return 0;
}
