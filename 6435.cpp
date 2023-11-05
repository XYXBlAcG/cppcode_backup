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
const int N = 2e5 + 5;
int n, m, ss, tt, s, t, head[N], pedge = 1, vl[N], val, dis[N], vis[N], fl[N], path[N], res[N], result, fires, las, cnt[N], a1, a2, b1, b2;
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
std::queue<int> que;
struct SPFA{
    bool spfa(){
        que = {};
        memset(dis, 0x3f, sizeof(dis));
        // memset(vis, 0, sizeof(vis));
        // memset(cnt, 0, sizeof(cnt));
        dis[s] = 0, fl[s] = INF, fl[t] = 0, vis[s] = 1;
        que.push(s);
        while(que.size()){
            int u = que.front(); que.pop();
            vis[u] = 0;
            for (int i = head[u]; i; i = edge[i].nxt){
                int v = edge[i].ver, w = edge[i].w, f = edge[i].f;
                if(w && dis[v] > dis[u] + f){
                    dis[v] = dis[u] + f;
                    fl[v] = std::min(fl[u], w);
                    path[v] = i;
                    // cnt[v] = cnt[u] + 1;
                    // if(cnt[v] > n) exit(0);
                    if(!vis[v]) vis[v] = 1, que.push(v);
                }
            }
        }
        return fl[t];
    }
}spfa;
struct Ans{
    int flow, val;
}ans;
struct EK{
    void dfs(){
        int p = t;
        ans.flow += fl[t];
        while(p ^ s){
            int i = path[p];
            edge[i].w -= fl[t];
            edge[i ^ 1].w += fl[t];
            ans.val += fl[t] * edge[i].f;
            p = edge[i ^ 1].ver;
        }
    }
    void ek(){
        ans = {0, 0};
        while(spfa.spfa()) dfs();
    }
}ek;
signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &ss, &tt), s = n + 1, t = n + 2;
    int tmpres = 0;
    for (int i = 1, w, v, l, u, p; i <= m; i++){
        scanf("%lld%lld%lld%lld%lld", &w, &v, &l, &u, &p);
        // add(w, v, u - l, p), vl[w] -= l, vl[v] += l, res[i] = l;
        if(p >= 0) add(w, v, u - l, p), vl[w] -= l, vl[v] += l, tmpres += l * p;
        else add(v, w, u - l, -p), vl[w] -= u, vl[v] += u, tmpres += u * p;
    }
    for (int i = 1; i <= n; i++){
        if(!vl[i]) continue;
        if(vl[i] > 0) add(s, i, vl[i], 0), val += vl[i];
        else add(i, t, -vl[i], 0);
    }
    // add(tt, ss, INF, 0); 
    addedge(tt, ss, INF, 0), addedge(ss, tt, INF, 0);
    ek.ek();
    // printf("flow = %lld, val = %lld\n", ans.flow, val);
    // printf("ans.val = %lld\n", ans.val);
    // printf("tmp = %lld\n", tmpres);
    if(ans.flow != val){
        puts("No solution.");
    }else{
        // for (int i = 1; i <= m; i++) ans.val += res[i] * edge[i << 1 | 1].f;
        ans.val += tmpres;
        printf("%lld\n", result = ans.val);
        for (int i = head[s]; i; i = edge[i].nxt) edge[i] = {0, 0, 0, 0};
        for (int i = head[t]; i; i = edge[i].nxt) edge[i] = {0, 0, 0, 0};
        
        int tmp = edge[pedge].w - INF;
        edge[pedge].w = 0, edge[pedge - 1].w = 0;
        s = ss, t = tt;
        ek.ek();
        // printf("%lld %lld\n", a1 = las = ans.flow + tmp, a2 = fires = ans.val + result);
        a1 = las = ans.flow + tmp, a2 = fires = ans.val + result;
        s = tt, t = ss;
        ek.ek();
        // printf("%lld %lld\n", b1 = las - ans.flow, b2 = fires + ans.val);
        b1 = las - ans.flow, b2 = fires + ans.val;
        printf("%lld %lld\n", b1, b2);
        printf("%lld %lld\n", a1, a2);
    }
    return 0;
}