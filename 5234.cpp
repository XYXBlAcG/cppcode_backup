#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f
#define ls(u) u << 1
#define rs(u) u << 1 | 1
#define mn(u) node[u].mn
using std::cin;
using std::cout;
using std::string;
const int N = 4e5 + 5;
int n, q, v[N], pdfn, ll[N], rr[N], dep[N], fa[N][21], root, id[N];
std::vector<int> st[N];
struct Node{
    int mn;
}node[N];
struct Tree{
    void pushup(int u){mn(u) = std::min(mn(ls(u)), mn(rs(u))); }
    void build(int u, int l, int r){
        if(l == r) return void(mn(u) = v[id[l]]);
        int mid = (l + r) >> 1;
        build(ls(u), l, mid);
        build(rs(u), mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int pos, int val){
        if(l > pos || r < pos) return;
        if(l == r) return void(mn(u) = val);
        int mid = (l + r) >> 1;
        modify(ls(u), l, mid, pos, val);
        modify(rs(u), mid + 1, r, pos, val);
        pushup(u);
    }
    int query(int u, int l, int r, int ql, int qr){
        if(l > qr || r < ql) return INF;
        if(ql <= l && r <= qr) return mn(u);
        int mid = (l + r) >> 1;
        return std::min(query(ls(u), l, mid, ql, qr), query(rs(u), mid + 1, r, ql, qr));
    }
}tree;
struct LCA{
    void predfs(int u, int fath){
        ll[u] = ++pdfn, id[pdfn] = u; 
        dep[u] = dep[fath] + 1;
        fa[u][0] = fath;
        for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (auto v : st[u]) predfs(v, u);
        rr[u] = pdfn;
    }
    int lca(int a, int b){
        if(a == b) return a;
        if(dep[a] < dep[b]) std::swap(a, b);
        for (int i = 19; ~i; i--) if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
        if(a == b) return a;
        for (int i = 19; ~i; i--) if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
        return fa[a][0];
    }
    int qry(int x){
        if(x == root) return tree.query(1, 1, n, 1, n);
        int lc = lca(x, root), rt = root;
        if(x == lc){
            for (int i = 19; ~i; i--) if(dep[fa[rt][i]] > dep[x]) rt = fa[rt][i];
            return std::min(tree.query(1, 1, n, 1, ll[rt] - 1), tree.query(1, 1, n, rr[rt] + 1, n));
        }
        return tree.query(1, 1, n, ll[x], rr[x]);
    }
}tr;
int main(){
    std::ios::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1, fa, vl; i <= n; i++){
        cin >> fa >> vl;
        st[fa].push_back(i), v[i] = vl;
    }
    root = 1;
    tr.predfs(1, 0);
    tree.build(1, 1, n);
    for (int i = 1, x, y; i <= q; i++){
        char op;
        cin >> op >> x;
        if(op == 'V'){
            cin >> y;
            tree.modify(1, 1, n, ll[x], y);
        }else if(op == 'E'){
            root = x;
        }else{
            cout << tr.qry(x) << '\n';
        }
    }
    return 0;
}