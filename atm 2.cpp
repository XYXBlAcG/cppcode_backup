#include <cstdio>
#include <vector>
#include <queue>
#define int long long
const int N = 1e6 + 5;
int n, m, val[N], s, p, pl[N], sta[N], psta, dfn[N], low[N], vis[N], dfncnt, pres, res[N], ind[N], ans[N], vis2[N], dist[N];
int v[500011];
struct Edge{
    int u, v;
}edge[N];
std::vector<int> st[N], ed[N];
std::queue<int> q;
void dfs(int u){
    dfn[u] = low[u] = ++dfncnt;
    vis[sta[++psta] = u] = 1;
    for (auto v : st[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        }else if(vis[v]){
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        int top;
        do{
            top = sta[psta--];
            res[top] = u;
            vis[top] = 0;
            if(top != u) val[u] += val[top];
        }while(top != u);
    }
}
int dfs2(int u){
    if(vis2[u]) return ans[u]; vis2[u] = 1;
    int result = dist[u] ? 0 : -0x3f3f3f3f;
    for (auto v : ed[u]){
        int tmp = dfs2(v);
        result = std::max(result, tmp);
    }
    return ans[u] = result+ val[u];
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v; i <= m; i++){
        scanf("%lld%lld", &u, &v);
        edge[i] = {u, v};
        st[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) scanf("%lld", val + i);
    for (int i = 1; i <= n; i++) if(!dfn[i]) dfs(i);
    // for(int i=1;i<=n;i++)v[res[i]]+=val[i];
    // for(int i=1;i<=4;i++)printf("val[i]=%lld\n",v[i]);
    scanf("%lld%lld", &s, &p);
    s = res[s];
    for (int i = 1; i <= p; i++) scanf("%lld", pl + i), dist[res[pl[i]]] = 1;
    for (int i = 1; i <= m; i++){
        if(res[edge[i].u] != res[edge[i].v]){
            // printf("add edge = %lld %lld\n", res[edge[i].u], res[edge[i].v]);
            ed[res[edge[i].u]].push_back(res[edge[i].v]);
        }
    }
    printf("%lld\n", dfs2(s));
    return 0;
}