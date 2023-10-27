#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <cstring>
#define int long long
using std::cin;
using std::cout;
using std::string;
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define tag(u) node[u].tag
#define sum(u) node[u].sum
const int N = 4e5 + 5;
std::vector<int> st[N];
int n, m, c[N], co[N], fst[N], hv[N], hsz[N], sz[N], dfn[N], pdfn, fa[N], dep[N], to[N];
struct Node{
    int sum, tag;
}node[N << 2];
struct Tree{
    void pushdown(int u, int mid){
        if(tag(u) != -1) tag(ls(u)) = tag(rs(u)) = c[mid] = c[mid + 1] = tag(u), sum(ls(u)) = sum(rs(u)) = 1, tag(u) = -1;
    }
    void pushup(int u, int mid){
        sum(u) = sum(ls(u)) + sum(rs(u)) - (c[mid] == c[mid + 1]);
    }
    // void debug(int u, int l, int r){
    //     if(l == r){
    //         printf("%lld -> %lld\n", l, c[l]);
    //         return;
    //     }
    //     int mid = (l + r) >> 1;
    //     pushdown(u, mid);
    //     printf("[%lld, %lld], sum = %lld, tag = %lld\n", l, r, sum(u), tag(u));
    //     debug(ls(u), l, mid);
    //     debug(rs(u), mid + 1, r);
    //     pushup(u, mid);
    // }
    void build(int u, int l, int r){
        if(l == r){
            node[u] = {1, -1}, to[l] = u;
            return;
        }
        tag(u) = -1;
        int mid = (l + r) >> 1;
        build(ls(u), l, mid), build(rs(u), mid + 1, r);
        pushup(u, mid);
    }
    void modify(int u, int l, int r, int ql, int qr, int val){
        if(l > qr || r < ql) return;
        if(ql <= l && r <= qr){
            tag(u) = c[l] = c[r] = val, sum(u) = 1;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(u, mid);
        modify(ls(u), l, mid, ql, qr, val);
        modify(rs(u), mid + 1, r, ql, qr, val);
        pushup(u, mid);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return 0;
        if(ql <= l && r <= qr) return sum(u);
        int mid = (l + r) >> 1;
        pushdown(u, mid);
        int L = query(ls(u), l, mid, ql, qr), R = query(rs(u), mid + 1, r, ql, qr);
        pushup(u, mid);
        return L + R - (c[mid] == c[mid + 1] && ql <= mid && qr > mid);
    }
}tree;
struct Lian{
    void dfs1(int u, int fath){
        fa[u] = fath;
        dep[u] = dep[fath] + 1;
        for (auto v : st[u]){
            if(v == fath) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            if(sz[v] > sz[hv[u]]) hv[u] = v;
        }
        sz[u]++;
    }
    void dfs2(int u){
        dfn[u] = ++pdfn;
        if(hv[u]) fst[hv[u]] = fst[u], dfs2(hv[u]);
        hsz[u] = hsz[hv[u]] + 1;
        for (auto v : st[u]){
            if(fa[u] == v || hv[u] == v) continue;
            fst[v] = v, dfs2(v);
        }
    }
    void init(){
        dfs1(1, 0), fst[1] = 1, dfs2(1);
    }
    void modify(int u, int v, int val){
        while(fst[u] != fst[v]){
            if(dep[fst[u]] < dep[fst[v]]) std::swap(u, v);
            tree.modify(1, 1, n, dfn[fst[u]], dfn[u], val);
            u = fa[fst[u]];
        }
        if(dep[u] > dep[v]) std::swap(u, v);
        tree.modify(1, 1, n, dfn[u], dfn[v], val);
    }
    int query(int u, int v){
        int ans = 0, tu = u, tv = v;
        while(fst[u] != fst[v]){
            if(dep[fst[u]] < dep[fst[v]]) std::swap(u, v);
            ans += tree.query(1, 1, n, dfn[fst[u]], dfn[u]);
            u = fa[fst[u]];
        }
        if(dep[u] > dep[v]) std::swap(u, v);
        ans += tree.query(1, 1, n, dfn[u], dfn[v]);
        u = tu, v = tv;
        while(fst[u] != fst[v]){
            if(dep[fst[u]] < dep[fst[v]]) std::swap(u, v);
            if(c[dfn[fa[fst[u]]]] == c[dfn[fst[u]]]) ans--;
            u = fa[fst[u]];
        }
        return ans;
    }
}lian;
// void color(){
//     puts("----------------");
//     for (int i = 1; i <= n; i++){
//         printf("%lld -> %lld\n", i, c[i]);
//     }
//     puts("----------------");
// }
signed main(){
    std::ios::sync_with_stdio(0);
    cin >> n >> m;
    memset(c, -1, sizeof(c));
    for (int i = 1; i <= n; i++) cin >> co[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        st[u].push_back(v), st[v].push_back(u);
    }
    lian.init();
    for (int i = 1; i <= n; i++) c[dfn[i]] = co[i];
    tree.build(1, 1, n);
    for (int i = 1, a, b, c; i <= m; i++){
        string op;
        cin >> op;
        // color();
        // tree.debug(1, 1, n);
        if(op == "C"){
            cin >> a >> b >> c;
            lian.modify(a, b, c);
        }else{
            cin >> a >> b;
            cout << lian.query(a, b) << '\n';
        }
    }
    return 0;
}