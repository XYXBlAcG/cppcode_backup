#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 1e5 + 5, M = 2e5 + 5;
int n, m, head[N], pedge = 1, s, t, dis[N], que[N], cur[N], res[M], vl[M], val;
struct Edge{
    int nxt, ver, w;
}edge[M];
void addedge(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
void add(int u, int v, int w){
    addedge(u, v, w);
    addedge(v, u, 0);
}
bool bfs(){
    memset(dis, -1, sizeof(dis));
    dis[que[1] = s] = 0;
    for (int i = 1, pque = 1; i <= pque; i++){
        for (int j = head[que[i]]; j; j = edge[j].nxt){
            if(edge[j].w && dis[edge[j].ver] == -1){
                dis[que[++pque] = edge[j].ver] = dis[que[i]] + 1;
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
int dinic(){
    int ans = 0;
    while(bfs()) ans += dfs(s, INF);
    return ans;
}
signed main(){
    scanf("%lld%lld", &n, &m), s = n + 1, t = n + 2;
    for (int i = 1, w, v, l, u; i <= m; i++){
        // scanf("%lld%lld%lld%lld", &w, &v, &l, &u);
        scanf("%lld%lld%lld", &w, &v, &l), u = 1;
        add(w, v, u - l), vl[w] -= l, vl[v] += l, res[i] = l;
    }
    for (int i = 1; i <= n; i++){
        if(vl[i] > 0) add(s, i, vl[i]), val += vl[i];
        else add(i, t, -vl[i]);
    }
    int ans = dinic();
    printf("a, v = %lld %lld\n", ans, val);
    if(ans != val){
        puts("0");
    }else{
        puts("1");
        for (int i = 1; i <= m; i++)
            printf("%lld ", edge[i << 1 | 1].w + res[i]);
        putchar('\n');
    }
    return 0;
}