#include<iostream>
#include<algorithm>
#include<stdio.h>
#define S(n) scanf("%d", &n)
#define R return
using namespace std;

typedef int I;

bool f (I i,I j) {R (i>j);}

I d,n,C[32],t;

I l(I c,I s)
{
    if(c>d)R 0;
    if(c==d)R s;
    for (I i=0; i<n;) {
        if(t=l(c+C[i++],s+1))R t;}
    R 0;
}

I main(void){
    S(d);S(n);
    for (I i=0;i<n;) 
        S(C[i++]);
    sort(C,C+n,f);
    I result=l(0,0);
    (!result)?cout<<"Roberta acknowledges defeat.\n":cout<<"Roberta wins in "<< result <<" strokes.\n";
    R 0;
}
