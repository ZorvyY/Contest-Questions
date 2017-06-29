#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunction (int i,int j) { return (i>j); }

struct tile {
    bool is_floor;
    bool is_calculated;
};

tile plan[27][27];

int roomCalc (int i, int j) {
    if (!(plan[i][j].is_floor)) return 0;
    if (plan[i][j].is_calculated) return 0;
    plan[i][j].is_calculated = true;
    return (1 + roomCalc(i+1, j) + roomCalc(i - 1, j) + roomCalc(i, j + 1) + roomCalc (i, j - 1));
}

int main() {
    int flooring;
    int rowN;
    int colN;
    cin >> flooring >> rowN >> colN;
    
    char temp;
    
    vector<int> rooms;
    
    for (int i = 0;  i < 27; i++){
        for (int j = 0; j < 27; j++) {
            plan[i][j].is_floor = false;
            plan[i][j].is_calculated = false;
        }
    }
    
    for (int i = 1; i <= rowN; i++) {
        for (int j = 1; j <= colN; j++) {
            cin >> temp;
            if (temp == '.') {
                plan[i][j].is_floor = true;
            }
        }
    }
    
    
    
    int size;
    
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) {
            if (plan[i][j].is_floor){
                if (!(plan[i][j].is_calculated)) {
                    //cout << "calced" << i << ", " << j << endl;
                    size = (roomCalc(i, j));
                    //cout << size << endl;
                    rooms.push_back(size);
                    //cout << "in room: " << rooms[0] << endl;
                }
            }
        }
    }
    
    sort(rooms.begin(), rooms.end());
    
    
    /*
    for (int i = 0; i < rooms.size(); i++) {
        cout << rooms[i] << " ";
    }
    
    cout << "line 79" << endl;
    */
    int roomcount = 0;
    
    while (rooms[rooms.size() - 1] <= flooring) {
        roomcount++;
        flooring -= rooms[rooms.size() - 1];
        rooms.pop_back();
        if (rooms.size() == 0) break;
    }
    
    if (roomcount == 1) {
        cout << roomcount << " room, " << flooring << " square metre(s) left over";
    } else {
        cout << roomcount << " rooms, " << flooring << " square metre(s) left over";
    }
    
    //cout << "98" << endl;
    
	return 0;
}

