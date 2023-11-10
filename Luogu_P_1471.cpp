#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mid ((l + r) >> 1)
#define sum(u) node[u].sum
const int N = 1e5 + 5;
int n, m;
struct Node{
    int sum;
    Node(){sum = 0;}
}node[N];
Node operator+ (Node a, Node b){
    
}
struct Tree{
    void pushup(int u){

    }
    void pushdown(int u){

    }
    void build(int u, int l, int r){
        if(l == r){
            return;
        }
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int u, int l, int r, int ql, int qr, int val){
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr){
            return;
        }
        modify(ls(u), l, mid, ql, qr, val), modify(rs(u), mid + 1, r, ql, qr, val);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(ql > r || qr < l) return 0;
        if(ql <= l && r <= qr){
            return 0;
        }
        return query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
    }
}tree;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, op, x, y, k; i <= m; i++){
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1){
            scanf("%d", &k);

        }else if(op == 2){

        }else{

        }
    }
    return 0;
}