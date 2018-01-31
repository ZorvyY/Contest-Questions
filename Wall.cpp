#include <iostream>
#include <string.h>
#include <stdio.h>

inline void scan(int *a){register char c=0;while(c<33)c=getchar_unlocked();*a=0;while(c>33){*a=*a*10+c-'0';c=getchar_unlocked();}}

using namespace std;

struct Node { int l,r,val,op; };

Node tree[8000000];
int ans[2000010];

void build(int l,int r,int idx) {
//    printf("Build node from %d to %d at index %d\n", l,r,idx);
    tree[idx].l = l;
    tree[idx].r = r;
    tree[idx].val = -1;
    if (l==r) {
        ans[idx] = 0;
        return;
    }
    int mid = (l+r)/2;
    build (l,mid,2*idx);
    build (mid+1,r,2*idx+1);
}

void resolve(int idx);    

void update(int updL, int updR, int val, int op, int idx){
//    printf("Updating : L = %d, R = %d, val = %d, op = %d, idx = %d\n", updL, updR, val, op, idx);
    if (updL <= tree[idx].l && updR >= tree[idx].r) {
        if (tree[idx].op == op) {
            if (op == 1) {
                tree[idx].val = max(val, tree[idx].val);
            } else if (op == 2) {
                tree[idx].val = min(val, tree[idx].val);
            }
        } else {
            if (tree[idx].val != -1) resolve(idx);
            tree[idx].op = op;
            tree[idx].val = val;
        }
        return;
    }
    if (updL > tree[idx].r || updR < tree[idx].l) {
//        printf("Update ignored\n");
        return;
    }
//    printf("Splitting update\n");
    if (tree[idx].val != -1) resolve(idx);
    update(updL,updR,val,op,2*idx);
    update(updL,updR,val,op,2*idx+1);
    tree[idx].val = -1;
}

void resolve(int idx) {
    if (tree[idx].l == tree[idx].r) {
//        printf("Updating leaf\n");
        if (tree[idx].op == 2) {
            ans[tree[idx].l] = min(tree[idx].val, ans[tree[idx].l]);
        } else if (tree[idx].op == 1) {
            ans[tree[idx].l] = max(tree[idx].val, ans[tree[idx].l]);
        }
        return;
    }
//    printf("Update called from resolve\n");
    update(tree[idx].l,tree[idx].r,tree[idx].val,tree[idx].op,2*idx);
//    printf("Update called from resolve\n");
    update(tree[idx].l,tree[idx].r,tree[idx].val,tree[idx].op,2*idx+1);
}

void resolveAndPrint(int idx) {
//    printf("resolve and print on %d to %d\n", tree[idx].l, tree[idx].r);
    if (tree[idx].val != -1) resolve(idx);
    if (tree[idx].r == tree[idx].l) {
        //printf("%d: at node %d\n", ans[tree[idx].l], tree[idx].l);
        printf("%d\n", ans[tree[idx].l]);
        return;
    }
    resolveAndPrint(2*idx);resolveAndPrint(2*idx+1);
    return;
}

int main () {
    int N;int K;
    scan(&N);scan(&K);
    build (0, N-1, 1);
    int op, l, r, h;
    for (int i = 0; i < K; i++) {
        scan(&op);
        scan(&l);
        scan(&r);
        scan(&h);
        update(l, r, h, op, 1);
    }
    resolveAndPrint(1);

    return 0;
}
