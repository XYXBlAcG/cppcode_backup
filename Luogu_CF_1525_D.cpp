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
const int N = 4e4 + 5;
int n, s, t, fl[N], dis[N], pedge = 1, vis[N], head[N], path[N];
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
struct Ans{
    int val, flow;
}ans;
std::queue<int> q;
struct EK{
    bool spfa(){
        q = {};
        memset(dis, 0x3f, sizeof(dis));
        q.push(s), fl[s] = INF, fl[t] = 0, dis[s] = 0, vis[s] = 1;
        while(q.size()){
            int u = q.front(); q.pop(), vis[u] = 0;
            for (int i = head[u]; i; i = edge[i].nxt){
                int v = edge[i].ver, w = edge[i].w, f = edge[i].f;
                if(dis[v] > dis[u] + f && w){
                    dis[v] = dis[u] + f;
                    path[v] = i;
                    fl[v] = std::min(fl[u], w);
                    if(!vis[v]) q.push(v), vis[v] = 1;
                }
            }
        }
        return fl[t];
    }
    void search(){
        int p = t;
        ans.flow += fl[t];
        while(p ^ s){
            int i = path[p];
            edge[i].w -= fl[t];
            edge[i ^ 1].w += fl[t];
            ans.val += edge[i].f * fl[t];
            p = edge[i ^ 1].ver;
        }
    }
    void solve(){
        ans = {0, 0};
        while(spfa()){
            search();
        }
    }
}ek;
signed main(){
    scanf("%lld", &n), s = n + 1, t = n + 2;
    for (int i = 1, c; i <= n; i++){
        scanf("%lld", &c);
        if(c) add(s, i, 1, 0);
        else add(i, t, 1, 0);
    }
    for (int i = 1; i <= n; i++){
        if(i > 1) add(i, i - 1, INF, 1);
        if(i < n) add(i, i + 1, INF, 1);
    }
    ek.solve();
    printf("%lld\n", ans.val);
    return 0;
}