#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <bitset>
#define ls(u) node[u].ls
#define rs(u) node[u].rs
#define sum(u) node[u].sum
#define mid ((l + r) >> 1)
#define ba(u, v) node[u].b[v]
#define b(u) node[u].b
const int N = 1e3 + 5, M = 1e5 + 5;
int n, m, q, rt[M], cnt;
struct Node{
    int ls, rs, sum;
    std::bitset<N> b;
}node[M * 35];
struct Tree{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void upd(int u){
        sum(u) = b(u).count();
    }
    void pushup(int u){
        sum(u) = sum(ls(u)) + sum(rs(u));
    }
    void build(int& u, int l, int r){
        if(!u) u = ++cnt;
        if(l == r) return;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int& u, int l, int r, int pos, int j, int val){
        if(l > pos || r < pos) return;
        u = clone(u);
        if(l == r){
            ba(u, j) = val;
            upd(u);
            return;
        }
        modify(ls(u), l, mid, pos, j, val), modify(rs(u), mid + 1, r, pos, j, val);
        pushup(u);
    }
    void reverse(int& u, int l, int r, int pos){
        if(l > pos || r < pos) return;
        u = clone(u);
        if(l == r){
            for (int i = 1; i <= m; i++) b(u).flip(i);
            upd(u);
            return;
        }
        reverse(ls(u), l, mid, pos), reverse(rs(u), mid + 1, r, pos);
        pushup(u);
    }
}tree;
int main(){
    scanf("%d%d%d", &n, &m, &q);
    tree.build(rt[0], 1, n);
    for (int _ = 1; _ <= q; _++){
        int op = 0, i = 0, j = 0, k = 0;
        scanf("%d", &op);
        if(op != 4) rt[_] = tree.clone(rt[_ - 1]);
        if(op == 1){
            scanf("%d%d", &i, &j);
            tree.modify(rt[_], 1, n, i, j, 1);
        }else if(op == 2){
            scanf("%d%d", &i, &j);
            tree.modify(rt[_], 1, n, i, j, 0);
        }else if(op == 3){
            scanf("%d", &i);
            tree.reverse(rt[_], 1, n, i);
        }else{
            scanf("%d", &k);
            // rt[_] = tree.clone(rt[k]);
            rt[_] = rt[k];
        }
        printf("%d\n", sum(rt[_]));
    }
    return 0;
}