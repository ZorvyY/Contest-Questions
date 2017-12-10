#include <iostream>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j) { return (i>j); }

int dist;
int numClubs;

int find(int current, int clubs[], int steps)
{
   // cout << "\ncurrent = " << current << endl;
   // cout << "\ncalled with current = " + current << endl;
    if (current > dist) return -1;
    if (current == dist) return steps;
    int ans = -1;
    for (int i = 0; i < numClubs; i++) {
   //     cout << "calling find #" + i << endl;
        int temp;
        temp = find(current + clubs[i], clubs, steps + 1);
        //if (temp != -1 && temp < ans) ans = temp;
        if (temp != -1) return temp;
    }
    //if (ans != -1) return ans;
    return -1;
}

int main(void)
{
    cin >> dist;
    cin >> numClubs;
    int clubs[numClubs];

    for (int i = 0; i < numClubs; i++) {
        cin >> clubs[i];
    }
    sort(clubs, clubs + numClubs, myfunction);
    
    /*
    for (int i = 0; i < numClubs; i++) {
        cout << clubs[i] << " ";
    }
*/
    
    int result = find(0,clubs,0);

    if (result == -1) {
        cout << "Roberta acknowledges defeat." << endl;
    } else {
        cout << "Roberta wins in " << result << " strokes." << endl;
    }
    //cout << find(0,clubs,0) << endl; 
    
    return 0;

}
