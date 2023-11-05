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
int n, m, head[N], pedge = 1, dis[N], vis[N], s, t, path[N], fl[N], val, wt, blc;
struct Edge{
    int nxt, ver, w, f;
}edge[N];
inline void addedge(int u, int v, int w, int f){
    edge[++pedge] = {head[u], v, w, f};
    head[u] = pedge;
}
inline void add(int u, int v, int w, int f, int c = 0){
    if(c) std::swap(u, v);
    // printf("add f = %lld\n", f);
    // printf("%lld <-> %lld, %lld\n", u, v, f);
    addedge(u, v, w, f);
    addedge(v, u, 0, -f);
}
struct Ans{
    int flow, val;
}ans;
struct EK{
    std::queue<int> q;
    inline bool spfa(){
        q = {};
        memset(dis, 0x3f, sizeof(dis));
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
    inline void search(){
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
    Ans ek(){
        ans = {0, 0};
        while(spfa()) search();
        return ans;
    }
}ek;
inline int get(int i, int j){
    return i * (m + 1) + j;
    // return (i - 1) * m + j;
}
inline int up(int i, int j){
    return 4 * get(i, j);
}
inline int down(int i, int j){
    return 4 * get(i, j) + 1;
}
inline int left(int i, int j){
    return 4 * get(i, j) + 2;
}
inline int right(int i, int j){
    return 4 * get(i, j) + 3;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    s = 4 * (n + 1) * (m + 1) + 2, t = s + 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1, p; j <= m; j++){
            scanf("%lld", &p);
            int c = (i + j) & 1;
            if(c){
                wt += __builtin_popcount(p);
            }else blc += __builtin_popcount(p);
            // printf("%lld %lld -> %lld\n", i, j, c);
            // puts("---------");
            if(!c){
                // if(i > 1) add(left(i, j), right(i - 1, j), 1, 0);
                // if(i < n) add(right(i, j), left(i + 1, j), 1, 0);
                // if(j > 1) add(down(i, j), up(i, j - 1), 1, 0);
                // if(j < m) add(up(i, j), down(i, j + 1), 1, 0);
                if(i > 1) add(up(i, j), down(i - 1, j), 1, 0);
                if(i < n) add(down(i, j), up(i + 1, j), 1, 0);
                if(j > 1) add(left(i, j), right(i, j - 1), 1, 0);
                if(j < m) add(right(i, j), left(i, j + 1), 1, 0);
            }
            // printf("p = %lld\n", p);
            if(p == 1){ // 0001
                if(!c) add(s, up(i, j), 1, 0), val++;
                else add(up(i, j), t, 1, 0);
                add(up(i, j), right(i, j), 1, 1, c);
                add(up(i, j), left(i, j), 1, 1, c);
                add(up(i, j), down(i, j), 1, 2, c);
            }else if(p == 2){ // 0010
                if(!c) add(s, right(i, j), 1, 0), val++;
                else add(right(i, j), t, 1, 0);
                add(right(i, j), up(i, j), 1, 1, c);
                add(right(i, j), left(i, j), 1, 2, c);
                add(right(i, j), down(i, j), 1, 1, c);
            }else if(p == 3){ // 0011
                if(!c) add(s, up(i, j), 1, 0), add(s, right(i, j), 1, 0), val += 2;
                else add(up(i, j), t, 1, 0), add(right(i, j), t, 1, 0);
                add(up(i, j), down(i, j), 1, 1, c);
                add(right(i, j), left(i, j), 1, 1, c);
            }else if(p == 4){ // 0100
                if(!c) add(s, down(i, j), 1, 0), val++;
                else add(down(i, j), t, 1, 0);
                add(down(i, j), up(i, j), 1, 2, c);
                add(down(i, j), left(i, j), 1, 1, c);
                add(down(i, j), right(i, j), 1, 1, c);
            }else if(p == 5){ // 0101
                if(!c) add(s, down(i, j), 1, 0), add(s, up(i, j), 1, 0), val += 2;
                else add(down(i, j), t, 1, 0), add(up(i, j), t, 1, 0);
            }else if(p == 6){ // 0110
                if(!c) add(s, right(i, j), 1, 0), add(s, down(i, j), 1, 0), val += 2;
                else add(right(i, j), t, 1, 0), add(down(i, j), t, 1, 0);
                add(down(i, j), up(i, j), 1, 1, c);
                add(right(i, j), left(i, j), 1, 1, c);
            }else if(p == 7){ // 0111
                if(!c) add(s, up(i, j), 1, 0), add(s, right(i, j), 1, 0), add(s, down(i, j), 1, 0), val += 3;
                else add(up(i, j), t, 1, 0), add(right(i, j), t, 1, 0), add(down(i, j), t, 1, 0);
                add(right(i, j), left(i, j), 1, 2, c);
                add(down(i, j), left(i, j), 1, 1, c);
                add(up(i, j), left(i, j), 1, 1, c);
            }else if(p == 8){ // 1000
                if(!c) add(s, left(i, j), 1, 0), val++;
                else add(left(i, j), t, 1, 0);
                add(left(i, j), up(i, j), 1, 1, c);
                add(left(i, j), right(i, j), 1, 2, c);
                add(left(i, j), down(i, j), 1, 1, c);
            }else if(p == 9){ // 1001
                if(!c) add(s, up(i, j), 1, 0), add(s, left(i, j), 1, 0), val += 2;
                else add(up(i, j), t, 1, 0), add(left(i, j), t, 1, 0);
                add(up(i, j), down(i, j), 1, 1, c);
                add(left(i, j), right(i, j), 1, 1, c);
            }else if(p == 10){ // 1010
                if(!c) add(s, right(i, j), 1, 0), add(s, left(i, j), 1, 0), val += 2;
                else add(right(i, j), t, 1, 0), add(left(i, j), t, 1, 0);
            }else if(p == 11){ // 1011
                if(!c) add(s, up(i, j), 1, 0), add(s, right(i, j), 1, 0), add(s, left(i, j), 1, 0), val += 3;
                else add(up(i, j), t, 1, 0), add(right(i, j), t, 1, 0), add(left(i, j), t, 1, 0);
                add(right(i, j), down(i, j), 1, 1, c);
                add(left(i, j), down(i, j), 1, 1, c);
                add(up(i, j), down(i, j), 1, 2, c);
            }else if(p == 12){ // 1100
                if(!c) add(s, down(i, j), 1, 0), add(s, left(i, j), 1, 0), val += 2;
                else add(down(i, j), t, 1, 0), add(left(i, j), t, 1, 0);
                add(down(i, j), up(i, j), 1, 1, c);
                add(left(i, j), right(i, j), 1, 1, c);
            }else if(p == 13){ // 1101
                if(!c) add(s, up(i, j), 1, 0), add(s, left(i, j), 1, 0), add(s, down(i, j), 1, 0), val += 3;
                else add(up(i, j), t, 1, 0), add(left(i, j), t, 1, 0), add(down(i, j), t, 1, 0);
                add(left(i, j), right(i, j), 1, 2, c);
                add(down(i, j), right(i, j), 1, 1, c);
                add(up(i, j), right(i, j), 1, 1, c);
            }else if(p == 14){ // 1110
                if(!c) add(s, down(i, j), 1, 0), add(s, right(i, j), 1, 0), add(s, left(i, j), 1, 0), val += 3;
                else add(down(i, j), t, 1, 0), add(right(i, j), t, 1, 0), add(left(i, j), t, 1, 0);
                add(right(i, j), up(i, j), 1, 1, c);
                add(left(i, j), up(i, j), 1, 1, c);
                add(down(i, j), up(i, j), 1, 2, c);
            }else if(p == 15){ // 1111
                if(!c) add(s, up(i, j), 1, 0), add(s, down(i, j), 1, 0), add(s, left(i, j), 1, 0), add(s, right(i, j), 1, 0), val += 4;
                else add(up(i, j), t, 1, 0), add(down(i, j), t, 1, 0), add(left(i, j), t, 1, 0), add(right(i, j), t, 1, 0);
            }
        }
    }
    Ans ans = ek.ek();
    // printf("flow = %lld, val = %lld\n", ans.flow, val);
    if(ans.flow != val || wt ^ blc) puts("-1");
    else printf("%lld\n", ans.val);
    return 0;
}