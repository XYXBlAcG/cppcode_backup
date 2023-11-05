#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f
const int N = 2e5 + 5;
int s, t, n, m, head[N], head2[N], pedge2 = 1, pedge = 1, dis[N], que[N], cur[N], vl[N], val, res[N], start, result[N], pres;
std::vector<int> fires;
struct Edge{
    int nxt, ver, w;
}edge[N], edge2[N];
struct Edger{
    int u, v;
}edger[N];
void addedge(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void add(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
void addedge2(int u, int v){
    edge2[++pedge2] = {head2[u], v, 0};
    head2[u] = pedge2;
}
void add2(int u, int v){
    addedge2(u, v);
}
struct Dinic{
    bool bfs(){
        memset(dis, -1, sizeof(dis));
        dis[que[1] = s] = 0;
        for (int i = 1, pque = 1; i <= pque; i++){
            int top = que[i];
            for (int j = head[top]; j; j = edge[j].nxt)
                if(edge[j].w && dis[edge[j].ver] == -1)
                    dis[que[++pque] = edge[j].ver] = dis[top] + 1;
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
int vis[N];
void dfs(int u){
    // printf("%lld ", u);
    for (int &i = head2[u]; i;){
        // if(!vis[i]) {
        //     vis[i] = 1;
            // vis[i >> 1] = 1;
            int cur = i;
            i = edge2[i].nxt;
            dfs(edge2[cur].ver);
        // }
    }
    result[++pres] = u;

}
signed main(){
    scanf("%lld%lld", &n, &m), s = n + 1, t = n + 2;
    for (int i = 1, u, v, t; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &t);
        edger[i] = {u, v};
        add(u, v, 1 - t);
        vl[u] -= t, vl[v] += t, res[i] += t;
    }
    for (int i = 1; i <= n; i++){
        if(vl[i] > 0) add(s, i, vl[i]);
        else add(i, t, -vl[i]);
    }
    dinic.solve();
    for (int i = 1; i <= m; i++){
        if(edge[i << 1 | 1].w + res[i]){
            if(!start) start = edger[i].u;
            add2(edger[i].u, edger[i].v);
            // printf("add %lld <-> %lld\n", edger[i].u, edger[i].v);
        }
    }
    dfs(start);
    for (int i = pres; i; i--) printf("%lld ", result[i]);
    putchar('\n');
    return 0;
}