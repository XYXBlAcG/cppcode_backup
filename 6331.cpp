#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define sum(u) node[u].sum
#define tag(u) node[u].tag
#define yes(u, v) ((mp[u * (n + 1) + v] == 1) || (mp[v * (n + 1) + u] == 1))
const int N = 1e5 + 5;
int n, m, sz[N], fst[N], fa[N], dep[N], hv[N], dfn[N], pdfn, res[N], cnt;
std::vector<int> st[N];
struct Node{
    int sum, tag;
}node[N * 4];
std::unordered_map<int, int> mp;
struct Op{
    int op, u, v;
}qry[N];
struct Tree{
    void pushdown(int u){
        if(!tag(u)) return;
        sum(ls(u)) = sum(rs(u)) = 0;
        tag(ls(u)) = tag(rs(u)) = 1;
        tag(u) = 0;
    }
    void pushup(int u){
        sum(u) = sum(ls(u)) + sum(rs(u));
    }
    void build(int u, int l, int r){
        if(l == r) {
            sum(u) = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr){
            sum(u) = 0, tag(u) = 1;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(u);
        modify(ls(u), l, mid, ql, qr), modify(rs(u), mid + 1, r, ql, qr);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return 0;
        if(ql <= l && r <= qr) return sum(u);
        int mid = (l + r) >> 1;
        pushdown(u);
        return query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr);
    }
}tree;
struct Lian{
    void dfs1(int u, int fath){
        sz[u]++;
        dep[u] = dep[fath] + 1;
        fa[u] = fath;
        for (auto v : st[u]){
            if(fa[u] == v || sz[v] || yes(u, v)) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            if(sz[hv[u]] < sz[v]) hv[u] = v;
        }
        
    }
    void dfs2(int u){
        dfn[u] = ++pdfn;
        if(hv[u]) fst[hv[u]] = fst[u], dfs2(hv[u]);
        for (auto v : st[u]){
            if(fa[u] == v || hv[u] == v || yes(u, v)) continue;
            fst[v] = v, dfs2(v);
        }
    }
    void mdf(int u, int v){
        while(fst[u] ^ fst[v]){
            if(dep[fst[u]] < dep[fst[v]]) std::swap(u, v);
            tree.modify(1, 1, n, dfn[fst[u]], dfn[u]);
            u = fa[fst[u]];
        }
        if(dep[u] >= dep[v]) std::swap(u, v);
        tree.modify(1, 1, n, dfn[u], dfn[v]);
    }
    int qry(int u, int v){
        int res = 0;
        while(fst[u] ^ fst[v]){
            if(dep[fst[u]] < dep[fst[v]]) std::swap(u, v);
            res += tree.query(1, 1, n, dfn[fst[u]], dfn[u]);
            u = fa[fst[u]];
        }
        if(dep[u] >= dep[v]) std::swap(u, v);
        res += tree.query(1, 1, n, dfn[u], dfn[v]);
        return res;
    }
    void dfs3(int u){
        for (auto v : st[u]){
            if(yes(u, v)) continue;
            if(fa[v] == u) dfs3(v);
            if(fa[u] ^ v && dfn[v] < dfn[u]) mdf(u, v);
        }
    }
    void init(){
        dfs1(1, 0), fst[1] = 1, dfs2(1);
        tree.build(1, 1, n), dfs3(1);
    }
}lian;
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
        mp[u * (n + 1) + v] = mp[v * (n + 1) + u] = 1;
    }
    int op, u, v;
    while(1){
        scanf("%d", &op);
        if(op == -1) break;
        if(op == 0) mp[u * (n + 1) + v] = mp[v * (n + 1) + u] = 1;
        scanf("%d%d", &u, &v), qry[++cnt] = {op, u, v};
    }
    lian.init();
    for (int i = cnt; i; i--){
        if(qry[i].op) res[i] = lian.qry(qry[i].u, qry[i].v);
        else lian.mdf(qry[i].u, qry[i].v);
    }
    for (int i = 1; i <= cnt; i++) if(qry[i].op) printf("%d\n", res[i]);
    return 0;
}