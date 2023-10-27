#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#define INF 0x3f3f3f3f
#define int long long
const int N = 1e5 + 5, M = 55;
int r, c, d, head[N], pedge = 1, s, t, que[N], dis[N], cur[N], res;
std::string h[M], a[M];
std::vector<std::pair<int, int>> zhu;
struct Edge{
    int nxt, ver, w;
}edge[N];
void add(int u, int v, int w){
    edge[++pedge] = {head[u], v, w};
    head[u] = pedge;
}
int g(int x, int y, int op){
    return op * M * M + x * M + y + 3;
}
bool bfs(){
    memset(dis, 0, sizeof(dis));
    dis[que[1] = s] = 1;
    for (int i = 1, pque = 1; i <= pque; i++){
        for (int j = head[que[i]]; j; j = edge[j].nxt){
            if(edge[j].w && !dis[edge[j].ver]){
                dis[que[++pque] = edge[j].ver] = dis[que[i]] + 1;
            }
        }
    }
    if(!dis[t]) return 0;
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
int pw(int x){return x * x;}
bool chk(int x, int y){
    return x - d < 1 || y - d < 1 || x + d > r || y + d > c;
}
bool getdis(int x, int y, int xx, int yy){
    return pw(x - xx) + pw(y - yy) <= pw(d);
}
void adde(int u, int v, int cs){
    add(u, v, cs);
    add(v, u, 0);
}
void addedge(){
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if(h[i][j - 1] != '0'){
                zhu.push_back({i, j});
                if(chk(i, j)) adde(g(i, j, 1), t, INF);
                adde(g(i, j, 0), g(i, j, 1), h[i][j - 1] - '0');
            }
        }
    }
    for (auto v : zhu){
        for (auto z : zhu){
            if(v != z){
                if(getdis(v.first, v.second, z.first, z.second)){
                    adde(g(v.first, v.second, 1), g(z.first, z.second, 0), INF);
                }
            }
        }
    }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if(a[i][j - 1] == 'L'){
                res++;
                adde(s, g(i, j, 0), 1);
            }
        }
    }
}
signed main(){
    scanf("%lld%lld%lld", &r, &c, &d);
    s = 0, t = 1;
    for (int i = 1; i <= r; i++)
        std::cin >> h[i];
    for (int i = 1; i <= r; i++)
        std::cin >> a[i];
    addedge();
    printf("%lld\n", res - solve());
    return 0;
}