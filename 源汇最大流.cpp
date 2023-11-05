#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 6e5 + 5;
int head[N], pedge = 1, n, m, s, t, que[N], dis[N], cur[N];
struct Edge{
    int nxt, ver, w;
}edge[N];
void addedge(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void add(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
struct Dinic{
    bool bfs(){
        memset(dis, -1, sizeof(dis));
        dis[que[1] = s] = 0;
        for (int i = 1, pque = 1; i <= pque; i++){
            int u = que[i];
            for (int j = head[u]; j; j = edge[j].nxt){
                int v = edge[j].ver, w = edge[j].w;
                if(w && dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    que[++pque] = v;
                }
            }
        }
        if(dis[t] == -1) return 0;
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
}dinic;
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, c; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &c);
        add(u, v, c);
    }
    printf("%lld\n", dinic.solve());
    return 0;
}