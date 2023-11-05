#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 4e5 + 5;
int n, m, s, t, dis[N], que[N], head[N], pedge = 1, cur[N], ans[N], vl[N], ss, tt, val;
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
                int v = edge[j].ver;
                if(edge[j].w && dis[v] == -1){
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
    scanf("%lld%lld%lld%lld", &n, &m, &ss, &tt), s = n + 1, t = n + 2;
    for (int i = 1, w, v, l, u; i <= m; i++){
        scanf("%lld%lld%lld%lld", &w, &v, &l, &u);
        add(w, v, u - l), vl[w] -= l, vl[v] += l;
    }
    add(tt, ss, INF);
    for (int i = 1; i <= n; i++){
        if(vl[i] > 0) add(s, i, vl[i]), val += vl[i];
        else add(i, t, -vl[i]);
    }
    // s = ss, t = tt;
    if(dinic.solve() != val){
        puts("0");
    }else{
        // add(tt, ss, 0);
        s = tt, t = ss;
        puts("1");
        printf("%lld\n", INF - dinic.solve());
    }
    return 0;
}