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
const int N = 1e5 + 5;
int pedge = 1, head[N], n, m, s, t, fl[N], path[N], dis[N], vis[N];
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
    int flow, val;
}ans;
struct EK{
    std::queue<int> q;
    bool spfa(){
        q = {};
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s] = 0, vis[s] = 1, fl[s] = INF, fl[t] = 0, q.push(s);
        while(q.size()){
            int u = q.front(); q.pop();
            vis[u] = 0;
            for (int i = head[u]; i; i = edge[i].nxt){
                int v = edge[i].ver, w = edge[i].w, f = edge[i].f;
                if(w && dis[v] > dis[u] + f){
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
            ans.val += fl[t] * edge[i].f;
            p = edge[i ^ 1].ver;
        }
    }
    Ans solve(){
        ans = {0, 0};
        while(spfa()) search();
        return ans;
    }
}ek;
// std::queue<int> que;
// struct SPFA{
//     bool spfa(){
//         que = {};
//         memset(dis, 0x3f, sizeof(dis));
//         // memset(vis, 0, sizeof(vis));
//         dis[s] = 0, vis[s] = 1, fl[s] = INF, fl[t] = 0;
//         que.push(s);
//         while(que.size()){
//             int u = que.front(); que.pop(), vis[u] = 0;
//             for (int i = head[u]; i; i = edge[i].nxt){
//                 int v = edge[i].ver, w = edge[i].w, f = edge[i].f;
//                 if(w && dis[v] > dis[u] + f){
//                     dis[v] = dis[u] + f;
//                     fl[v] = std::min(fl[u], w);
//                     path[v] = i;
//                     if(!vis[v]) que.push(v), vis[v] = 1;
//                 }
//             }
//         }
//         return fl[t];
//     }
// }spfa;
// struct Ans{
//     int flow, val;
// };
// Ans operator+(Ans a, Ans b){return {a.flow + b.flow, a.val + b.val};}
// struct EK{
//     Ans ans = {0, 0};
//     void dfs(){
//         int p = t;
//         ans.flow += fl[t];
//         while(p ^ s){
//             int i = path[p];
//             edge[i].w -= fl[t];
//             edge[i ^ 1].w += fl[t];
//             ans.val += fl[t] * edge[i].f;
//             p = edge[i ^ 1].ver;
//         }
//         return;
//     }
//     Ans solve(){
//         while(spfa.spfa()) dfs();
//         return ans;
//     }
// }ek;

signed main(){
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for (int i = 1, u, v, c, p; i <= m; i++){
        scanf("%lld%lld%lld%lld", &u, &v, &c, &p);
        add(u, v, c, p);
    }
    Ans ans = ek.solve();
    printf("%lld\n%lld\n", ans.flow, ans.val);
    return 0;
}