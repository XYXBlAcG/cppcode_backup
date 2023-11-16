#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 2e5 + 5;
int t, n, c[N], v[N], las, pedge, head[N], dis[N];
struct Edge{
    int nxt, ver;
}edge[N * 2];
void addedge(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
void clean(){
    for (int i = 0; i <= n; i++) v[c[i]] = 0, c[i] = 0;
    for (int i = 0; i <= n; i++) head[i] = 0;
    pedge = 0;
}
int dfs(int u, int fa, int cnt){
    if(v[u]) return 0;
    if(cnt >= las) return INF;
    int ans = INF;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(v == fa) continue;
        ans = std::min(ans, dfs(v, u, cnt + 1) + 1);
    }
    return ans;
}
void solve(){
    v[c[0]] = 1;
    las = INF;
    for (int i = 1; i < n; i++){
        if(las == 1){
            printf("1 ");
            continue;
        }
        las = std::min(las, dfs(c[i], 0, 0)), v[c[i]] = 1;
        printf("%d ", las);
    }
    putchar('\n');
}
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", c + i);
        for (int i = 1, u, v; i < n; i++){
            scanf("%d%d", &u, &v);
            addedge(u, v), addedge(v, u);
        }
        solve();
        clean();
    }
    return 0;
}