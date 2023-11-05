#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) node[u].ls
#define rs(u) node[u].rs
#define v(u) node[u].v
#define f(u) rt[u].f
#define d(u) rt[u].d
const int N = 2e5 + 5;
int n, m, ans, cnt;
struct Root{
    int f, d;
}rt[N * 40];
struct Node{
    int v, ls, rs;
}node[N * 40];
struct Tree{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void build(int& u, int l, int r, int vl, int w){
        if(!u) u = ++cnt;
        if(l == r){
            v(u) = vl * l + w;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, vl, w), build(rs(u), mid + 1, r, vl, w);
    }
    void modify(int& u, int l, int r, int pos, int val){
        if(l > pos || r < pos) return;
        u = clone(u);
        if(l == r){
            v(u) = val;
            return;
        }
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, pos, val);
        modify(rs(u), mid + 1, r, pos, val);
    }
    int query(int u, int l, int r, int pos){
        if(l > pos || r < pos) return 0;
        if(l == r) return v(u);
        int mid = (l + r) >> 1;
        return query(ls(u), l, mid, pos) | query(rs(u), mid + 1, r, pos);
    }
    int find(int& u, int b){
        int a = 0;
        while((a = query(u, 1, n, b)) != b)
            b = a;
        return b;
    }
}fa, dep;
struct UFS{
    void merge(int u, int a, int b){
        a = fa.find(f(u), a), b = fa.find(f(u), b);
        if(a == b) return;
        int da = dep.query(d(u), 1, n, a), db = dep.query(d(u), 1, n, b);
        if(da < db) std::swap(da, db), std::swap(a, b);
        fa.modify(f(u), 1, n, b, a);
        if(da == db) dep.modify(d(u), 1, n, a, da + 1);
    }
}ufs;
int main(){
    scanf("%d%d", &n, &m);
    fa.build(f(0), 1, n, 1, 0);
    dep.build(d(0), 1, n, 0, 1);
    for (int i = 1, op, a, b, k; i <= m; i++){
        scanf("%d", &op);
        if(op == 1){
            rt[i] = rt[i - 1];
            scanf("%d%d", &a, &b), a ^= ans, b ^= ans;
            ufs.merge(i, a, b);
        }else if(op == 2){
            scanf("%d", &k), k ^= ans;
            rt[i] = rt[k];
        }else{
            rt[i] = rt[i - 1];
            scanf("%d%d", &a, &b), a ^= ans, b ^= ans;
            printf("%d\n", ans = bool(fa.find(f(i), a) == fa.find(f(i), b)));
        }
    }
    return 0;
}