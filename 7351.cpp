#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 5;
int n, m, fa[N][21], dep[N], dfn[N], pdfn, vis[N], ans;
struct Node{
    int v, w;
};
std::vector<Node> st[N], vt[N];
std::vector<int> p, builder;
void addedge(int u, int v, int w){
    vt[u].push_back({v, w});
}
struct LCA{
    void predfs(int u, int fath){
        dfn[u] = ++pdfn;
        dep[u] = dep[fath] + 1;
        fa[u][0] = fath;
        for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (auto v : st[u])
            if(v.v != fath) predfs(v.v, u);
    }
    int lca(int a, int b){
        if(a == b) return a;
        if(dep[a] < dep[b]) std::swap(a, b);
        for (int i = 19; ~i; i--) if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
        if(a == b) return a;
        for (int i = 19; ~i; i--) if(fa[a][i] ^ fa[b][i]) a = fa[a][i], b = fa[b][i];
        return fa[a][0];
    }
}lca;
bool cmp(int a, int b){return dfn[a] < dfn[b];}
void buildtree(){
    std::sort(p.begin(), p.end(), cmp);
    builder.clear();
    for (int i = 0; i < (int)p.size(); i++){
        builder.push_back(p[i]);
        if(i != (int)p.size() - 1) builder.push_back(lca.lca(p[i], p[i + 1]));
    }
    std::sort(builder.begin(), builder.end(), cmp);
    builder.erase(std::unique(builder.begin(), builder.end()), builder.end());
    for (int i = 0; i < (int)builder.size() - 1; i++){
        int u = builder[i], v = builder[i + 1];
        int lc = lca.lca(u, v), w = INF;
        if(dep[u] < dep[v]) std::swap(u, v);
        for (int i = 19; ~i; i--) if(dep[fa[u][i]] >= dep[v]) u = fa[u][i], w = std::min(w, );
        
    }
}

signed main(){
    scanf("%lld", &n);
    for (int i = 1, u, v, w; i <= n; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
    scanf("%lld", &m);
    for (int i = 1, k; i <= m; i++){
        scanf("%lld", &k);
        p.clear();
        for (int j = 1, poi; j <= k; j++){
            scanf("%lld", &poi), vis[poi] = 1;
            p.push_back(poi);
        }
        buildtree();
    }
    return 0;
}