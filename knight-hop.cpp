// https://wcipeg.com/problem/ccc10j5
#include <stdio.h>
#include <queue>


struct Pos {int row, col;};

int main(void)
{
    Pos start;
    scanf("%d %d", &start.row, &start.col);
    Pos end;
    scanf("%d %d", &end.row, &end.col);

    //bool vis[8][8] = {};
    
    std::queue<Pos> list;

    list.push(start);

    int counter = 0;

    while(!list.empty()) {
        //printf("\nNext loop:\n\n");
        int N = list.size();
        for (int x = 0; x < N; x++) {
            Pos elem = list.front();
            list.pop();
            int i = elem.row;
            int j = elem.col;
            if (i < 1 || i > 8) continue;
            if (j < 1 || j > 8) continue;

  //          printf("\n");
//            printf("i:%d j:%d\t", i, j);

            if (i == end.row && j == end.col) goto print;
            list.push((Pos){i-2,j+1});
            list.push((Pos){i-2,j-1});
            list.push((Pos){i+2,j+1});
            list.push((Pos){i+2,j-1});
            list.push((Pos){i-1,j+2});
            list.push((Pos){i-1,j-2});
            list.push((Pos){i+1,j+2});
            list.push((Pos){i+1,j-2});
        }
        /*
        for (int i = 0; i < list.size(); i++) {
            printf("i:%d j:%d\t", list[i].row, list[i].col);
        }
        */
        counter++;
        //printf("%d", counter);
        //if (counter > 5) break;
    }

    print:
    printf("%d", counter);
    
    return 0;
}
