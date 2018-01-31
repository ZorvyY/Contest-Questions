#include <algorithm>
#include <stdio.h>

using namespace std;

char f(int g) {
    if (g<0||g>100)return 'X';
    g=min((g<50)?3:(g/10),8);
    return 73-g;
}

int main() {
    printf(" -1 -> %c\n", f(-1));
    printf("  0 -> %c\n", f(0));
    printf(" 20 -> %c\n", f(20));
    printf(" 42 -> %c\n", f(42));
    printf(" 55 -> %c\n", f(55));
    printf(" 65 -> %c\n", f(65));
    printf(" 72 -> %c\n", f(72));
    printf(" 75 -> %c\n", f(75));
    printf(" 80 -> %c\n", f(80));
    printf(" 99 -> %c\n", f(99));
    printf("102 -> %c\n", f(102));
    printf("864 -> %c\n", f(864));
    return 0;

}

