#include <iostream> 
#include <stdio.h>
//#include <vector>

using namespace std;

inline void scan(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

int main(void)
{
    int arr[2001] = {};
    int N;
    cin >> N;
    int a;
    for (int i = 0; i < N; i++) {
        scan(&a);
        ++arr[a];
    }

    int lengths[4000] = {};

    for (int i = 1; i <= 2000; i++) {
        for (int j = i; j <= 2000; j++) {
            if (i == j) {
                lengths[i+j] += arr[i]/2;
            } else
            lengths[i+j] += min(arr[i], arr[j]);
        }
    }


/*
    for (int i = 1; i < 3999; i++) {
        int a = i/2;
        int b = i/2 + 1;
        while (--b >= 0 && ++a <= 2000) {
            lengths[i] += min(arr[a],arr[b]);
        }
    }
*/
    int idx = 0;
    int total = 0;
//    int max = 0;
    for (int i = 0; i < 3999; i++) {
/*        if (lengths[i] > 0) {
            printf("%d: %d\n", i, lengths[i]);
        }
        
*/        
        if (lengths[i] == lengths[idx]) ++total;
        if (lengths[i] > lengths[idx]) {
            idx = i;
            total = 1;
        }
    }
    printf("%d %d", lengths[idx], total);
    //cout << lengths[idx] << "\n" << idx;
    
    return 0;
}

