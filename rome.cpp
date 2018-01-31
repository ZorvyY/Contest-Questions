#include <iostream>
#include <stdio.h>
#include <map>
#include <unordered_map>
#define getchar getchar_unlocked
#define putchar putchar_unlocked

using namespace std;

unordered_map<char, int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

void parseRoman (int * a) {
    char n;
    string s = "";
    while ((n=getchar()) < 'Z' && n > 'A') {s += n; putchar(n);}
    putchar(n);
    char largest = 'I';
    int total = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (roman[s[i]] < roman[largest]) total -= roman[s[i]]; 
        else {
            total += roman[s[i]];
            largest = s[i];
        }
    }
    *a = total;
}
void printAns(int a) {
    string rom = "";
    if (a > 1000) {printf("CONCORDIA CUM VERITATE\n");return;}
//    if (a == 1000) {printf("M\n");return;}
    if (a >= 1000) {rom += "M"; a -= 1000;}
    if (a >= 900 && a < 1000)  {
        rom += "CM";
        a -= 900;
    }
    if (a >= 500) {rom += "D"; a -= 500;}
    if (a >= 400 && a < 500) {
        rom += "CD";
        a -= 400;
    }
    while (a >= 100) {rom += "C"; a -= 100;}

    if (a >= 90 && a < 100)  {
        rom += "XC";
        a -= 90;
    }
    if (a >= 50) {rom += "L"; a -= 50;}
    if (a >= 40 && a < 50) {
        rom += "XL";
        a -= 40;
    }
    while (a >= 10) {rom += "X"; a -= 10;}

    if (a >= 9 && a < 10)  {
        rom += "IX";
        a -= 9;
    }
    if (a >= 5) {rom += "V"; a -= 5;}
    if (a >= 4 && a < 5) {
        rom += "IV";
        a -= 4;
    }
    while (a >= 1) {rom += "I"; a -= 1;}

    printf("%s\n", rom.c_str());
}
    
int main(void)
{
    int N;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        int a,b;
        parseRoman(&a);parseRoman(&b);getchar();
        printAns(a+b);
    }
    return 0;
}
