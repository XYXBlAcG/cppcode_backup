#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 7e5 + 5;
int n, m, s, t, dis[N], head[N], pedge = 1, que[N], cur[N], vis[N];
struct Edge{
    int nxt, ver, w;
}edge[N];
struct Node{
    int u, v;
}node[N];
void addedge(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void add(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
struct Dinic{
    bool bfs() {
        memset(dis, -1, sizeof(dis));
        dis[que[1] = s] = 0;
        for (int i = 1, pque = 1; i <= pque; i++) {
            for (int j = head[que[i]]; j; j = edge[j].nxt) {
                if (edge[j].w && dis[edge[j].ver] == -1) {
                    dis[que[++pque] = edge[j].ver] = dis[que[i]] + 1;
                }
            }
        }
        if (dis[t] == -1)
            return 0;
        memcpy(cur, head, sizeof(head));
        return 1;
    }
    int dfs(int u, int w) {
        if (u == t)
            return w;
        int sum = 0;
        for (int& i = cur[u]; i; i = edge[i].nxt) {
            auto& v = edge[i];
            if (v.w && dis[v.ver] == dis[u] + 1) {
                int ret = dfs(v.ver, std::min(w, v.w));
                v.w -= ret;
                edge[i ^ 1].w += ret;
                sum += ret;
                if (!(w -= ret)) return sum;
            }
        }
        return sum;
    }
    void solve(){
        while(bfs()) dfs(s, INF);
    }
}dinic;
void dfs(int u){
    vis[u] = 1;
    for (int i = head[u]; i; i = edge[i].nxt){
        if(vis[edge[i].ver] || !edge[i].w) continue;
        dfs(edge[i].ver);
    }
}
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        node[i] = {u, v};
        add(u, v, w);
    }
    dinic.solve();
    dfs(s);
    for (int i = 1; i <= m; i++){
        if((vis[node[i].u] && !vis[node[i].v])){
            printf("%lld ", i);
        }
    }
    putchar('\n');
    // for (int i = 1; i <= m; i++){
    //     if(!edge[i << 1].w) printf("%lld\n", i);
    // }
    return 0;
}