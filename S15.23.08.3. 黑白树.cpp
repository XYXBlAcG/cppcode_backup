#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, pedge = 1, head[N], f[N][2], g[N][2], son[N], bro[N];
bool vf[N][2], vg[N][2], col[N];
struct Edge{
    int nxt, ver;
} edge[N * 4];
void addedge(int u, int v){
    edge[++pedge] = {head[u], v};
    head[u] = pedge;
}
void predfs(int u){
    int las = 0;
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        predfs(v);
        if(!son[u]) son[u] = v;
        else bro[las] = v;
        las = v;
    }
}
int dpg(int, bool);
int dpf(int u, bool k){
    if(!u) return !k;
    if(vf[u][k]) return f[u][k]; vf[u][k] = 1;
    int ans = 0, v = son[u];
    if(k) ans += dpg(v, k ^ col[u]);
    else ans += dpg(v, 0) + !col[u] * dpg(v, 1);
    return f[u][k] = ans % mod;
}
int dpg(int u, bool k){
    if(!u) return !k;
    if(vg[u][k]) return g[u][k]; vg[u][k] = 1;
    return g[u][k] = (dpf(u, 0) * dpg(bro[u], k)) % mod + k * (dpf(u, 1) * dpg(bro[u], 0)) % mod;
}
signed main(){
    #ifdef ONLINE_JUDGE
    freopen("bwtree.in", "r", stdin);
    freopen("bwtree.out", "w", stdout);
    #endif
    scanf("%lld", &n);
    for (int i = 1, p; i < n; i++)
        scanf("%lld", &p), addedge(p + 1, i + 1);
    for (int i = 1, p; i <= n; i++)
        scanf("%lld", &p), col[i] = p;
    return predfs(1), printf("%lld\n", dpf(1, !col[1])), 0;
}