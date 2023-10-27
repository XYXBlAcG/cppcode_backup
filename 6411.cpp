#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e3 + 5, M = 6e3 + 5;
int n, m, s, t, head[N], pedge = 1, dis[N], que[N], cur[N], sta[N], psta, las = INF;
struct Edge{
    int nxt, ver, w;
}edge[M];
void add(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
bool bfs(){
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[que[1] = s] = 0;
    for (int i = 1, pque = 1; i <= pque; i++){
        for (int j = head[que[i]]; j; j = edge[j].nxt){
            if(edge[j].w && dis[edge[j].ver] == INF){
                dis[que[++pque] = edge[j].ver] = dis[que[i]] + 1;
            }
        }
    }
    if(dis[t] == INF) return 0;
    memcpy(cur, head, sizeof(head));
    return 1;
}
int dfs(int u, int w){
    sta[++psta] = u;
    if(u == t){
        printf("%lld %lld ", psta, w);
        for (int i = 1; i <= psta; i++){
            printf("%lld ", sta[i]);
        }
        puts("");
        psta--;
        return w;
    }
    int sum = 0;
    for (int& i = cur[u]; i; i = edge[i].nxt){
        auto& v = edge[i];
        if(v.w && dis[v.ver] == dis[u] + 1){
            int ret = dfs(v.ver, std::min(w, v.w));
            v.w -= ret;
            sum += ret;
            if(!(w -= ret)) {psta--; return sum;}
        }
    }
    psta--;
    return sum;
}
void solve(){
    while(bfs())
        dfs(s, INF);
}
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, c; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &c);
        add(u, v, c);
    }
    solve();
    return 0;
}