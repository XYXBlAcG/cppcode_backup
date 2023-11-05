#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 5e5 + 5, M = 45, top = 35;
int n, m, s, t, que[N], dis[N], head[N], pedge = 1, cur[N], vis[N], in[N], val;
struct Node{
    int sc, at;
    std::vector<int> att;
}pl[M * M];
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
int get(int x, int y){
    return x * top + y;
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
                    // printf("dis %lld = %lld\n", v, dis[v]);
                    que[++pque] = v;
                }
            }
        }
        // printf("s, t - %lld %lld\n", s, t);
        // printf("dis t %lld\n", dis[t]);
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
std::queue<int> q;
void topo(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(!in[get(i, j)]) q.push(get(i, j)), vis[get(i, j)] = 1;
        }
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for (auto v : pl[u].att){
            in[v]--;
            if(!in[v] && !vis[v]) q.push(v), vis[v] = 1;
        }
    }
}
signed main(){
    scanf("%lld%lld", &n, &m), s = top * top + 1, t = s + 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%lld%lld", &pl[get(i, j)].sc, &pl[get(i, j)].at);
            for (int k = 1, x, y; k <= pl[get(i, j)].at; k++)
                scanf("%lld%lld", &x, &y), x++, y++, pl[get(i, j)].att.push_back(get(x, y)), in[get(x, y)]++;
            if(j ^ m) pl[get(i, j + 1)].att.push_back(get(i, j)), in[get(i, j)]++;
        }
    }
    topo();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(!vis[get(i, j)]) continue;
            if(pl[get(i, j)].sc > 0) add(s, get(i, j), pl[get(i, j)].sc), val += pl[get(i, j)].sc;
            else add(get(i, j), t, -pl[get(i, j)].sc);
            for (auto v : pl[get(i, j)].att){
                if(vis[v]) add(v, get(i, j), INF);
            }
        }
    }
    printf("%lld\n", val - dinic.solve());
    // dinic.solve();
    return 0;
}