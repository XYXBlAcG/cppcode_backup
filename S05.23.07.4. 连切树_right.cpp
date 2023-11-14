#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define f(u) for (int i = head[u], v = edge[i].ver; i; i = edge[i].nxt, v = edge[i].ver)
#define chk if (v == fath || edge[i].del) continue
const int N = 8e5 + 5;
int id, n, head[N], pedge = 1, d[N], pans, pl, vis[N], t;
struct Edge{
    int nxt, ver, del;
}edge[N];
struct Lian{
    int u, v;
}cn[N], sp[N];
void addedge(int u, int v){
    edge[++pedge] = {head[u], v, 0};
    head[u] = pedge;
}
void add(int u, int v){
    addedge(u, v), addedge(v, u), d[u]++, d[v]++;
}
void split(int u, int v, int i){
    edge[i].del = edge[i ^ 1].del = 1;
    d[u]--, d[v]--;
    sp[++pans] = {u, v};
}
void dfs(int u, int fath){
    int cnt = 0, fa = 0;
    f(u) if(v == fath && !edge[i].del) fa = i;
        else dfs(v, u);
    f(u) {chk; cnt++;}
    if(cnt <= 1) return;
    if(fath && fa) split(u, fath, fa);
    if(cnt == 2) return;
    int cur = cnt;
    f(u){
        chk;
        split(u, v, i);
        if((--cur) <= 2) break;
    }
}
void dfs(int u, int fath, int& res){
    int cur = 0;
    vis[u] = 1;
    f(u){
        if (v == fath || edge[i].del || vis[v]) continue;
        dfs(v, u, res), cur++;
    }
    if(!cur) res = u;
}
void solve(){
    // scanf("%d%d", &id, &n);
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++){
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    dfs(1, 0);
    printf("%d\n", pans);
    for (int i = 1, v; i <= n; i++){
        if(vis[i]) continue;
        if(!d[i]) cn[++pl] = {i, i};
        if(d[i] == 1)
            dfs(i, 0, v), cn[++pl] = {i, v};
    }
    for (int i = 1; i <= pans; i++){ 
        printf("%d %d %d %d\n", sp[i].u, sp[i].v, cn[i].u, cn[i + 1].v);
    }
}
void clean(){
    pans = 0, pl = 0, pedge = 1;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= n; i++){
        d[i] = vis[i] = 0;
    }
}
int main(){
    scanf("%d", &t);
    while(t--){
        solve();
        clean();
    }
    return 0;
}