#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 5;
int n, m, s, t, head[N], pedge = 1, dis[N], vis[N], fl[N], path[N];
struct Edge{
    int nxt, ver, w, f;
}edge[N];
void addedge(int u, int v, int w, int f){
    edge[++pedge] = {head[u], v, w, f};
    head[u] = pedge;
}
void add(int u, int v, int w, int f){
    addedge(u, v, w, f);
    addedge(v, u, 0, -f);
}
std::queue<int> q;
int maxflow, maxval;
struct EK{
    bool spfa(){
        q = {};
        memset(dis, 0x3f, sizeof(dis));
        // memset(vis, 0, sizeof(vis));
        dis[s] = 0, fl[s] = INF, fl[t] = 0, q.push(s), vis[s] = 1;
        while(q.size()){
            int u = q.front(); q.pop(); vis[u] = 0;
            for (int i = head[u]; i; i = edge[i].nxt){
                int v = edge[i].ver, w = edge[i].w, f = edge[i].f;
                if(w && dis[v] > dis[u] + f){
                    dis[v] = dis[u] + f;
                    path[v] = i;
                    fl[v] = std::min(fl[u], w);
                    if(!vis[v]) vis[v] = 1, q.push(v);
                }
            }
        }
        return fl[t];
    }
    void dfs(){
        int p = t;
        maxflow += fl[t];
        while(p ^ s){
            // printf("p = %lld\n", p);
            int i = path[p];
            edge[i].w -= fl[t];
            edge[i ^ 1].w += fl[t];
            maxval += fl[t] * edge[i].f;
            p = edge[i ^ 1].ver;
        }
    }
    void solve(){
        while(spfa()) dfs();
    }
}ek;
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, c, p; i <= m; i++){
        scanf("%lld%lld%lld%lld", &u, &v, &c, &p);
        add(u, v, c, p);
    }
    ek.solve();
    printf("%lld\n%lld\n", maxflow, maxval);
    return 0;
}