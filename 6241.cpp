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
const int N = 1e5 + 5;
int n, m, vl[N], ans, cnt, fa[N][21], dep[N], d[N], id[N], rt[N], R;
std::vector<int> st[N];
struct Node{
    int ls, rs, v;
}node[N];
struct Tree{
    int clone(int u){
        node[++cnt] = node[u];
        return cnt;
    }
    void build(int& u, int l, int r){
        if(!u) u = ++cnt;
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
    }
    void modify(int& u, int l, int r, int pos){
        if(l > pos || r < pos) return;
        u = clone(u), v(u)++;
        if(l == r) return;
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, pos);
        modify(rs(u), mid + 1, r, pos);
    }
    int query(int a, int b, int c, int d, int l, int r, int k){
        if(l == r) return l;
        int sum = v(ls(a)) + v(ls(b)) - v(ls(c)) - v(ls(d)), mid = (l + r) >> 1;
        if(sum >= k) return query(ls(a), ls(b), ls(c), ls(d), l, mid, k);
        return query(rs(a), rs(b), rs(c), rs(d), mid + 1, r, k - sum);
    }
}tree;
struct LCA{
    void predfs(int u, int fath){
        tree.modify(rt[u] = tree.clone(rt[fath]), 1, R, id[u]);
        dep[u] = dep[fath] + 1;
        fa[u][0] = fath;
        for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (auto v : st[u]) if(v ^ fath) predfs(v, u);
    }
    int lca(int a, int b){
        if(a == b) return a;
        if(dep[a] < dep[b]) std::swap(a, b);
        for (int i = 19; ~i; i--) if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
        if(a == b) return a;
        for (int i = 19; ~i; i--) if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
        return fa[a][0];
    }
}tr;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", vl + i), d[i] = vl[i];
    std::sort(vl + 1, vl + 1 + n);
    R = std::unique(vl + 1, vl + 1 + n) - vl - 1;
    for (int i = 1; i <= n; i++) id[i] = std::lower_bound(vl + 1, vl + 1 + R, d[i]) - vl;
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    tree.build(rt[0], 1, R);
    tr.predfs(1, 0);
    for (int i = 1, u, v, k; i <= m; i++){
        scanf("%d%d%d", &u, &v, &k), u ^= ans;
        int lc = tr.lca(u, v);
        // printf("u = %d, v = %d, lca = %d\n", u, v, lc);
        printf("%d", ans = vl[tree.query(rt[u], rt[v], rt[lc], rt[fa[lc][0]], 1, R, k)]);
        if(i != m) putchar('\n');
    }
    return 0;
}