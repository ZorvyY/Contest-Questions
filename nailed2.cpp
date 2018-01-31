#include <iostream> 
#include <stdio.h>
#include <map>
//#include <unordered_map>

using namespace std;

inline void scan(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

int main(void)
{
    map<int, int> arr;
    int N;
    cin >> N;
    int a;
    
    for (int i = 0; i < N; i++) {
        scan(&a);
        if (arr.count(a)) {
            ++arr[a];
        } else {
            arr[a] = 1;
        }
    }

    map<int, int> lengths;

    for (map<int, int>::iterator it=arr.begin(); it!=arr.end(); ++it) {
        for (map<int, int>::iterator jt=arr.begin(); jt!=arr.end(); ++jt) {
            int idx = it->first + jt -> first;
            if (!lengths.count(idx)) lengths[idx] = 0;
            if (it == jt) lengths[idx] += it->second/2;
            else
            lengths[idx] += min(it->second, jt->second);
        }
    }

    int max = 0;
    int count = 0;

    for (map<int, int>::iterator it=lengths.begin(); it!=lengths.end(); ++it) {
        it -> second /= 2;
        int h = it->first;
        int n = it->second;
        if (n >= max) {
            if (n == max) count++;
            else if (n > max) {
                max = n;
                count = 1;
            }
        }
    }

    printf ("%d %d", max, count);

    /*
    for (map<int, int>::iterator it=lengths.begin(); it!=lengths.end(); ++it) {
        printf ("%d: %d\n", it -> first, it -> second);
    }
    */

    
    return 0;
}

