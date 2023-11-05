#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define nd(u, v) node[u].ch[v]
using std::cin;
using std::cout;
using std::string;
const int N = 2e5 + 5;
int n, fa[N], dep[N], dfn[N], pdfn, q, sz[N], fst[N], hv[N], cnt, sum[N * 15], ans[N];
struct Edge{
    int v;
    string w;
};
std::vector<Edge> st[N];
string addstr, str[N], tmp[N];
struct Qry{
    int num, id;
    string str;
};
std::vector<Qry> qry[N];
struct Node{
    int ch[26];
}node[N * 15];
struct Trie{
    void insert(int id){
        int cur = 0;
        for (auto v : str[id]){
            if(!nd(cur, v - 'a')) nd(cur, v - 'a') = ++cnt;
            sum[cur]++, cur = nd(cur, v - 'a');
        }
        sum[cur]++;
    }
    int query(string str){
        int cur = 0;
        for (auto v : str){
            int p = nd(cur, v - 'a');
            if(!p) return 0;
            cur = p;
        }
        return sum[cur];
    }
}trie;
struct Tree{
    void dfs1(int u, int fath){
        fa[u] = fath;
        dep[u] = dep[fath] + 1;
        for (auto v : st[u]){
            if(v.v == fath) continue;
            tmp[v.v] = v.w;
            dfs1(v.v, u);
            sz[u] += sz[v.v];
            if(sz[v.v] > sz[hv[u]]) hv[u] = v.v;
        }
        sz[u]++;
    }
    void dfs2(int u){
        dfn[u] = ++pdfn, str[pdfn] = tmp[u];
        if(hv[u]) fst[hv[u]] = fst[u], dfs2(hv[u]);
        for (auto v : st[u]){
            if(v.v == fa[u] || hv[u] == v.v) continue;
            fst[v.v] = v.v, dfs2(v.v);
        }
    }
    void init(){
        dfs1(1, 0), fst[1] = 1, dfs2(1);
    }
    void insert(int x, int y, int id){
        while(fst[x] ^ fst[y]){
            if(dep[fst[x]] < dep[fst[y]]) std::swap(x, y);
            int l = dfn[fst[x]] - 1, r = dfn[x];
            qry[l].push_back({-1, id, addstr});
            qry[r].push_back({1, id, addstr});
            x = fa[fst[x]];
        }
        if(dep[x] > dep[y]) std::swap(x, y);
        qry[dfn[x]].push_back({-1, id, addstr});
        qry[dfn[y]].push_back({1, id, addstr});
    }
}tree;
int main(){
    std::ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1, u, v; i < n; i++){
        string s = "";
        cin >> u >> v >> s;
        st[u].push_back({v, s});
        st[v].push_back({u, s});
    }
    tree.init();
    cin >> q;
    for (int i = 1, u, v; i <= q; i++){
        cin >> u >> v >> addstr;
        tree.insert(u, v, i);
    }
    for (int i = 2; i <= n; i++){
        trie.insert(i);
        for (auto v : qry[i]) ans[v.id] += v.num * trie.query(v.str);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return 0;
}