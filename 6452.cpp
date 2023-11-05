#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 5, up = 105;
int n, m, s, t, head[N], pedge = 1, cur[N], dis[N], que[N], pans;
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
int get(int x, int y){
    return x * up + y;
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
    scanf("%lld%lld", &n, &m), s = (up + 1) * (up + 1) + 1, t = s + 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int mp = 0;
            scanf("%lld" , &mp);
            if(mp == 1) add(s, get(i, j), INF);
            else if(mp == 2) add(get(i, j), t, INF);
       }
    } 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++){
                int ti = i + "1102"[k] - '1', tj = j + "0211"[k] - '1';
                if(ti >= 1 && ti <= n && tj >= 1 && tj <= m) add(get(i, j), get(ti, tj), 1);
            }
            // if(j > 1) add(get(i, j - 1), get(i, j), 1);
            // if(j ^ m) add(get(i, j + 1), get(i, j), 1);
            // if(i > 1) add(get(i - 1, j), get(i, j), 1);
            // if(i ^ n) add(get(i + 1, j), get(i, j), 1);
        }
    }
    printf("%lld\n", dinic.solve());
    return 0;
}