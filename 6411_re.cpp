#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f
const int N = 1e5 + 5, M = 6e5 + 5;
int n, m, s, t, head[N], pedge = 1, dis[N], que[N], cur[N];
struct Edge{
    int nxt, ver, w;
}edge[M];
void add(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
bool bfs(){
    memset(dis, INF, sizeof(dis));
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
    if(u == t) return w;
    int sum = 0;
    for (int& i = cur[u]; i; i = edge[i].nxt){
        auto& v = edge[i];
        if(v.w && dis[v.ver] == dis[u] + 1){
            int ret = dfs(v.ver, std::min(w, v.w));
            v.w -= ret;
            edge[i ^ 1].w += ret;
            sum += ret;
            if(!(w -= ret)) return sum;
        }
    }
    return sum;
}
int solve(){
    int ans = 0;
    while(bfs()) ans += dfs(s, INF);
    return ans;
}
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, c; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &c);
        add(u, v, c);
        add(v, u, 0);
    }
    printf("%lld\n", solve());
    return 0;
}