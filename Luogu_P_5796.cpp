#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
const int N = 1e5 + 5, M = 55;
int n, m, s, t, head[N], bhead[N], pedge = 1, bpedge = 1, dis[N], cur[N], fl[N], path[N], vis[N];
struct Edge{
    int nxt, ver, w, f;
}edge[N], bedge[N];
int mp[M][M];
void addedge(int u, int v, int w, int f){
    edge[++pedge] = {head[u], v, w, f};
    head[u] = pedge;
}
void add(int u, int v, int w, int f){
    addedge(u, v, w, f);
    addedge(v, u, 0, -f);
}
struct Ans{
    int flow, val;
}res, ans;
std::queue<int> q;
struct EK{
    bool spfa(){
        memset(dis, 0x3f, sizeof(dis));
        dis[s] = 0, vis[s] = 1, fl[s] = INF, fl[t] = 0, q.push(s);
        while(q.size()){
            int u = q.front(); q.pop();
            vis[u] = 0;
            for (int i = head[u]; i; i = edge[i].nxt){
                int v = edge[i].ver, w = edge[i].w, f = edge[i].f;
                if(w && dis[v] > dis[u] + f){
                    dis[v] = dis[u] + f;
                    fl[v] = std::min(fl[u], w);
                    path[v] = i;
                    if(!vis[v]) q.push(v), vis[v] = 1;
                }
            }
        }
        return fl[t];
    }
    void search(){
        int p = t;
        ans.flow = fl[t];
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
        while(spfa()) search();
    }
}ek;
bool chk(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n && mp[x][y] != 2;
}
int get(int x, int y, int op){
    return (x * (n + 1) + y) * (op + 1);
}
void backup(){
    memcpy(bhead, head, sizeof(head));
    memcpy(bedge, edge, sizeof(edge));
    bpedge = pedge;
}
void backdown(){
    memcpy(head, bhead, sizeof(head));
    memcpy(edge, bedge, sizeof(edge));
    pedge = bpedge;
}
signed main(){
    scanf("%lld%lld", &n, &m), s = (n + 1) * (n + 1) + 1, t = s + 1;
    res = {INF, INF};
    for (int i = 1, x, y; i <= n; i++)
        scanf("%lld%lld", &x, &y), mp[x][y] = 1, add(s, get(x, y, 0), 1, 0);
    for (int i = 1, x, y; i <= m; i++)
        scanf("%lld%lld", &x, &y), mp[x][y] = 2;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            add(get(i, j, 0), get(i, j, 1), 1, 0);
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 0; k < 4; k++){
                int tx = i + "0211"[k] - '1', ty = j + "1102"[k] - '1';
                if(!chk(tx, ty)) continue;
                add(get(i, j, 1), get(tx, ty, 0), INF, 1);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        backup();
        for (int j = 1; j <= n; j++)
            add(get(i, j, 1), t, 1, 0);
        ek.solve();
        res.val = std::min(res.val, ans.val);
        backdown();
    }
    for (int i = 1; i <= n; i++){
        backup();
        for (int j = 1; j <= n; j++)
            add(get(j, i, 1), t, 1, 0);
        ek.solve();
        res.val = std::min(res.val, ans.val);
        backdown();
    }
    backup();
    for (int i = 1; i <= n; i++)
        add(get(i, i, 1), t, 1, 0);
    ek.solve();
    res.val = std::min(res.val, ans.val);
    backdown();
    backup();
    for (int i = 1; i <= n; i++)
        add(get(i, n - i + 1, 1), t, 1, 0);
    ek.solve();
    res.val = std::min(res.val, ans.val);
    backdown();
    printf("%lld\n", res.val);
    return 0;
}