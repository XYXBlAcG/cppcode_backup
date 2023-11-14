#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f3f3f3f3f
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mid ((l + r) >> 1)
#define int long long
const int N = 5e5 + 5;
int n, q, dfn[N], pdfn, sz[N], dis[N], id[N], lef[N], ans[N];
struct Node{int v, w;};
struct Qry{int l, r, id;};
std::vector<Node> st[N]; 
std::vector<Qry> qry[N];
int mn[N * 4], tag[N * 4];
struct Tree{
    void pushdown(int u){
        if(tag[u]) mn[ls(u)] += tag[u], mn[rs(u)] += tag[u], tag[ls(u)] += tag[u], tag[rs(u)] += tag[u], tag[u] = 0;
    }
    void pushup(int u){
        mn[u] = std::min(mn[ls(u)], mn[rs(u)]);
    }
    void build(int u, int l, int r){
        if(l == r) return void(mn[u] = ((lef[id[l]] == 1) ? dis[id[l]] : INF));
        build(ls(u), l, mid), build(rs(u), mid + 1, r), pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr, int val){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr){
            mn[u] += val, tag[u] += val;
            return;
        }
        pushdown(u);
        modify(ls(u), l, mid, ql, qr, val), modify(rs(u), mid + 1, r, ql, qr, val);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return INF;
        if(ql <= l && r <= qr) return mn[u];
        pushdown(u);
        return std::min(query(ls(u), l, mid, ql, qr), query(rs(u), mid + 1, r, ql, qr));
    }
}tree;
void predfs(int u, int fath){
    dfn[u] = ++pdfn, id[pdfn] = u;
    if((int)st[u].size() == 1 && u != 1) lef[u] = 1;
    for (auto v : st[u]){
        if(v.v == fath) continue;
        dis[v.v] = dis[u] + v.w;
        predfs(v.v, u);
        sz[u] += sz[v.v];
    }
    sz[u]++;
}
void dfs(int u, int fath){
    for (auto v : qry[u])
        ans[v.id] = tree.query(1, 1, n, v.l, v.r);
    for (auto v : st[u]){
        if(v.v == fath) continue;
        tree.modify(1, 1, n, dfn[v.v], dfn[v.v] + sz[v.v] - 1, -v.w);
        tree.modify(1, 1, n, 1, dfn[v.v] - 1, v.w);
        tree.modify(1, 1, n, dfn[v.v] + sz[v.v], pdfn, v.w);
        dfs(v.v, u);
        tree.modify(1, 1, n, dfn[v.v], dfn[v.v] + sz[v.v] - 1, v.w);
        tree.modify(1, 1, n, 1, dfn[v.v] - 1, -v.w);
        tree.modify(1, 1, n, dfn[v.v] + sz[v.v], pdfn, -v.w);
    }
}
signed main(){
    #ifdef ONLINE_JUDGE
    freopen("kings.in", "r", stdin);
    freopen("kings.out", "w", stdout);
    #endif
    scanf("%lld%lld", &n, &q);
    for (int i = 1, u, v, w; i < n; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        st[u].push_back({v, w}), st[v].push_back({u, w});
    }
    for (int i = 1, u, l, r; i <= q; i++){
        scanf("%lld%lld%lld", &u, &l, &r);
        qry[u].push_back({l, r, i});
    }
    predfs(1, 0);
    tree.build(1, 1, n);
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
        if(ans[i] >= 1e16) puts("N0T-FOUND");
        else printf("%lld\n", ans[i]);
    return 0;
}