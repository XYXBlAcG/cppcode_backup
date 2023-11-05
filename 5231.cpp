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
#define tr(u) node[u].tr
const int N = 1e5 + 5, top = 1e9;
int n, m, fa[N][21], dep[N], rt[N * 80], cnt, ans[N];
std::vector<int> st[N];
struct Node{
    int ls, rs, sum, tr;
}node[N * 80];
struct Tree{
    void pushup(int u){
        if(!ls(u) || !rs(u)) return void(sum(u) = sum(ls(u) | rs(u))), void(tr(u) = tr(ls(u) | rs(u)));
        if(sum(ls(u)) >= sum(rs(u))) sum(u) = sum(ls(u)), tr(u) = tr(ls(u));
        else sum(u) = sum(rs(u)), tr(u) = tr(rs(u));
    }
    void modify(int& u, int l, int r, int pos, int val){
        if(l > pos || r < pos) return;
        if(!u) u = ++cnt;
        if(l == r) return void(sum(u) += val), void(tr(u) = pos);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, pos, val), modify(rs(u), mid + 1, r, pos, val);
        pushup(u);
    }
    int merge(int a, int b, int l, int r){
        if(!a || !b) return a | b;
        if(l == r) return sum(a) += sum(b), a;
        int mid = (l + r) >> 1;
        ls(a) = merge(ls(a), ls(b), l, mid);
        rs(a) = merge(rs(a), rs(b), mid + 1, r);
        return pushup(a), a;
    }
    void Mdf(int x, int y, int lc, int z){
        modify(rt[x], 1, top, z, 1);
        modify(rt[y], 1, top, z, 1);
        modify(rt[lc], 1, top, z, -1);
        modify(rt[fa[lc][0]], 1, top, z, -1);
    }
}tree;
void predfs(int u, int fath){
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : st[u]){
        if(v == fath) continue;
        predfs(v, u);
    }
}
int lca(int a, int b){
    if(a == b) return a;
    if(dep[a] < dep[b]) std::swap(a, b);
    for (int i = 19; ~i; i--) if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    if(a == b) return a;
    for (int i = 19; ~i; i--) if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}
void dfs(int u, int fath){
    for (auto v : st[u]){
        if(v == fath) continue;
        dfs(v, u);
        rt[u] = tree.merge(rt[u], rt[v], 1, top);
    }
    ans[u] = sum(rt[u]) ? tr(rt[u]) : 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    predfs(1, 0);
    for (int i = 1, x, y, z; i <= m; i++){
        scanf("%d%d%d", &x, &y, &z);
        tree.Mdf(x, y, lca(x, y), z);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}