#include<iostream>
#include<algorithm>
#define R return
using namespace std;

typedef int I;

I d,n,C[33],t;

I l(I c,I s)
{
    if(c>d)R 0;
    if(c==d)R s;
    for(I i=n;i;) {
        if(t=l(c+C[i--],s+1))R t;}
    R 0;
}

I main(void){
    cin>>d>>n;
    for(I i=1;i<=n;) 
        cin>>C[i++];
    sort(C,C+n);
    I r=l(0,0);
    !r?cout<<"Roberta acknowledges defeat.\n":cout<<"Roberta wins in "<<r<<" strokes.\n";
    R 0;
}
