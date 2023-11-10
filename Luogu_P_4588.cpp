#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mid ((l + r) >> 1)
#define sum(u) node[u].sum
const int N = 1e5 + 5;
int t, q, M;
struct Node{
    int sum;
}node[N << 2];
struct Tree{
    void pushup(int u){
        sum(u) = (sum(ls(u)) * sum(rs(u))) % M;
    }
    void build(int u, int l, int r){
        if(l == r) return void(sum(u) = 1);
        build(ls(u), l, mid), build(rs(u), mid + 1, r), pushup(u);
    }
    void modify(int u, int l, int r, int pos, int val){
        if(pos > r || pos < l) return;
        if(l == r) return void(sum(u) = val);
        modify(ls(u), l, mid, pos, val), modify(rs(u), mid + 1, r, pos, val), pushup(u);
    }
}tree;
signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &q, &M);
        tree.build(1, 1, q);
        for (int i = 1, op, m; i <= q; i++){
            scanf("%lld%lld", &op, &m);
            if(op == 1) tree.modify(1, 1, q, i, m);
            else tree.modify(1, 1, q, m, 1);
            printf("%lld\n", sum(1) % M);
        }
    }
    return 0;
}