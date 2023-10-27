#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
const int N = 5e5 + 5;
int n, m, head[N], pedge = 1, dfn[N], low[N], pdfn, sta[N], psta, used[N], bcc[N], pbcc, sz[N], vis[N], ans, deg[N], sz2[N], fa[N];
struct Edge{
    int nxt, ver;
}edge[N];
std::vector<std::pair<int, int>> ed;
std::vector<int> st[N];
void add(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
void insert(int u, int v){
    ed.push_back({u, v});
}
void build(){
    std::sort(ed.begin(), ed.end());
    ed.erase(std::unique(ed.begin(), ed.end()), ed.end());
    for (auto v : ed){
        st[v.first].push_back(v.second);
        st[v.second].push_back(v.first);
        deg[v.first]++, deg[v.second]++;
    }
}
void tarjan(int u){
    dfn[u] = low[u] = ++pdfn;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(!used[i >> 1] && !bcc[i >> 1]){
            used[(sta[++psta] = i) >> 1] = 1;
        }
        if(!dfn[v]){
            tarjan(v);
            if(dfn[u] == low[v]){
                ++pbcc;
                insert(pbcc + n, u);
                while(used[i >> 1]){
                    int top = sta[psta--];
                    used[top >> 1] = 0;
                    bcc[top >> 1] = pbcc;
                    insert(pbcc + n, edge[top].ver);
                }
            }
            low[u] = std::min(low[u], low[v]);
        }else low[u] = std::min(low[u], dfn[v]);
    }
}
void predfs(int u){
    sz[u] = (u <= n);
    // printf("u %lld, sz = %lld\n", u, sz[u]);
    for (auto v : st[u]){
        if(fa[u] == v) continue;
        // printf("%lld -> %lld\n", u, v);
        fa[v] = u, predfs(v);
        sz[u] += sz[v];
    }
    // printf("u = %lld, sz = %lld\n", u, sz[u]);
}
void dfs(int u){
    if(fa[u]) sz2[u] = sz2[fa[u]] + sz[fa[u]] - sz[u];
    int sum = sz2[u] + sz[u];
    // printf("%lld %lld %lld\n", sz[u], sz2[u], sum);
    for (auto v : st[u]){
        if(fa[u] == v) continue;
        dfs(v);
    }
    if(u <= n){
        for (auto v : st[u])
            if(v ^ fa[u]) ans += sz[v] * (sum - sz[v] - 1);
        ans += sz2[u] * (sum - sz2[u] - 1);
        // printf("u = %lld, ans = %lld\n", u, ans);
    }else{
        // printf("deg %lld = %lld\n", u, deg[u]);
        for (auto v : st[u])
            if(v ^ fa[u]) ans += sz[v] * (sum - sz[v]) * (deg[u] - 2);
        ans += sz2[u] * (sum - sz2[u]) * (deg[u] - 2);
        // printf("u = %lld, ans = %lld\n", u, ans);
    }
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%lld%lld", &u, &v);
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    build();
    for (int i = 1; i <= pbcc + n; i++) if(!sz[i]) predfs(i);
    for (int i = 1; i <= pbcc + n; i++) if(!sz2[i]) dfs(i);
    printf("%lld\n", ans);
    return 0;
}
/*
1 -> 6
6 -> 2
2 -> 5
5 -> 3
5 -> 4
sz = 1, sz2 = 3, sum = 4
u = 3, ans = 0
sz = 1, sz2 = 3, sum = 4
u = 4, ans = 0
sz = 2, sz2 = 2, sum = 4
5 3
u = 5, ans = 10
sz = 3, sz2 = 1, sum = 4
u = 2, ans = 14
sz = 3, sz2 = 1, sum = 4
6 2
u = 6, ans = 14
sz = 4, sz2 = 0, sum = 4
u = 1, ans = 14
14
*/