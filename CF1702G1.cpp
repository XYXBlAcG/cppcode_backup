#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
int n, fa[N][21], dep[N], q, k, p[N];
std::vector<int> st[N];
void dfs(int u, int fath){
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : st[u]){
        if(v == fath) continue;
        dfs(v, u);
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
int main(){
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    dfs(1, 0);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++){
        scanf("%d", &k);
        for (int j = 1; j <= k; j++){
            scanf("%d", p + j);
        }
        int lc = 0, flg = 0;
        for (int j = 1; j < k; j++){
            int tmp = lca(p[j], p[j + 1]);
            if(!lc) lc = tmp;
            else if(lc != tmp) {
                int o = lca(lc, tmp);
                if(o != lc && o != tmp) {
                    flg = 1;
                    break;
                }
                lc = o;
            }
        }
        puts(flg ? "NO" : "YES");
    }
    return 0;
}