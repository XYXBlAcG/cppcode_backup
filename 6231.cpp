#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define ls(u) node[u].ls
#define rs(u) node[u].rs
#define vl(u) node[u].vl
#define tg(u) node[u].tag
const int N = 1e6 + 5, M = 5e5 + 5;
int n, m, a[N], rt[N * 4], cnt, ans;
struct Node{
    int ls, rs, vl, tag;
}node[N * 4 + M * 20 * 4];
struct Tree{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void pushdown(int u){
        ls(u) = clone(ls(u));
        rs(u) = clone(rs(u));
        vl(ls(u)) += tg(u);
        vl(rs(u)) += tg(u);
        tg(ls(u)) += tg(u);
        tg(rs(u)) += tg(u);
        tg(u) = 0;
    }
    void pushup(int u){
        vl(u) = std::max(vl(ls(u)), vl(rs(u)));
    }
    void build(int& u, int l, int r){
        if(!u) u = ++cnt;
        if(l == r){
            vl(u) = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int& u, int l, int r, int ql, int qr, int val){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr){
            vl(u) += val, tg(u) += val;
            ans = std::max(ans, vl(u));
            return;
        }
        pushdown(u);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, ql, qr, val);
        modify(rs(u), mid + 1, r, ql, qr, val);
        pushup(u);
    }
}tree;
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    tree.build(rt[0], 1, n);
    for (int i = 1, t, l, r, x; i <= m; i++){
        scanf("%lld%lld%lld%lld", &t, &l, &r, &x), t = ((t ^ ans) % i + i) % i, ans = -INF;
        tree.modify(rt[i] = tree.clone(rt[t]), 1, n, l, r, x);
        printf("%lld\n", ans);
    }
    return 0;
}