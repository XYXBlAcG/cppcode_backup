#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define ls(u) node[u].ls
#define rs(u) node[u].rs
#define sum(u) node[u].sum
#define mid ((l + r) >> 1)
const int N = 5e5 + 5;
int n, m, a[N], ans = 0, cnt, rt[N], d[N], id[N];
struct Node{
    int ls, rs, sum;
}node[N];
struct Tree{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void build(int& u, int l, int r){
        if(!u) u = ++cnt;
        if(l == r) return;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int& u, int l, int r, int pos){
        if(l > pos || r < pos) return;
        u = clone(u), sum(u)++;
        if(l == r) return;
        modify(ls(u), l, mid, pos), modify(rs(u), mid + 1, r, pos);
    }
    int query(int ql, int qr, int l, int r, int pos){
        if(l == r) return l;
        int sum = sum(ls(qr)) - sum(ls(ql));
        if(sum >= pos) return query(ls(ql), ls(qr), l, mid, pos);
        return query(rs(ql), rs(qr), mid + 1, r, pos - sum);
    }
}tree;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i), d[i] = a[i];
    std::sort(d + 1, d + 1 + n);
    int dlen = std::unique(d + 1, d + 1 + n) - d - 1;
    for (int i = 1; i <= n; i++) id[i] = std::lower_bound(d + 1, d + 1 + dlen, a[i]) - d;
    tree.build(rt[0], 1, dlen);
    for (int i = 1; i <= n; i++)
        tree.modify(rt[i] = tree.clone(rt[i - 1]), 1, dlen, id[i]);
    for (int i = 1, x, y, z, l, r, k; i <= m; i++){
        scanf("%d%d%d", &x, &y, &z);
        l = std::min((x + ans) % n, (y + ans) % n) + 1;
        r = std::max((x + ans) % n, (y + ans) % n) + 1;
        k = (z + ans) % (r - l + 1) + 1;
        k = (r - l + 1) - k + 1;
        // printf("l, r, k, %d %d %d\n", l, r, k);
        printf("%d\n", ans = d[tree.query(rt[l - 1], rt[r], 1, dlen, k)]);
    }
    return 0;
}