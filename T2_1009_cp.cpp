#include <cstdio>
#include <algorithm>
using std::lower_bound;
using std::max;
using std::sort;
using std::unique;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, k, c[311], s[311], head[311], pedge, son[311], bro[311], pw[311], p[311];
ll f[311][311][311], g[311][311][311];
bool visf[311][311][311], visg[311][311][311];
struct Edge {
    int ver, nxt;
} edge[311];
void add_edge(int u, int v) {
    edge[++pedge] = { v, head[u] };
    head[u] = pedge;
}
void dfs(int x) {
    s[x] = 1;
    int las = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int v = edge[i].ver;
        dfs(v);
        s[x] += s[v];
        if (!son[x])
            son[x] = v;
        if (las)
            bro[las] = v;
        las = v;
    }
    las = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int v = edge[i].ver;
        if (!las)
            c[v] = s[x] - s[v] - 1;
        else
            c[v] = c[las] - s[v];
        las = v;
    }
}
ll dpg(int v, int i, int j);
ll dpf(int v, int i, int j) {
    // printf("v=%d i=%d j=%d\n",v,i,j);
    if (j == 0)
        return inf;
    if (visf[v][i][j])
        return f[v][i][j];
    visf[v][i][j] = 1;
    //    int t=max(p[v],j);
    //    printf("t=%d p[v]=%d\n",t,p[v]);
    return f[v][i][j] = std::min(dpf(v, i, j - 1),
                                 j >= p[v] ? dpg(son[v], i - 1, j) + pw[j] - pw[p[v]] : dpg(son[v], i, j));
}
ll dpg(int v, int i, int j) {
    //	printf("v=%d i=%d j=%d\n",v,i,j);
    if (i < 0)
        return inf;
    if (v == 0)
        return i == 0 ? 0 : inf;
    if (visg[v][i][j])
        return g[v][i][j];
    visg[v][i][j] = 1;
    ll tmp = inf;
    for (int x = max(0, i - c[v]); x <= std::min(s[v], i); x++)
        tmp = std::min(tmp, dpg(bro[v], i - x, j) + dpf(v, x, j));
    return g[v][i][j] = tmp;
}
int main() {
    // freopen("radar.in", "r", stdin);
    // freopen("radar.out", "w", stdout);
    scanf("%d%d", &n, &k);
    int fa, root = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &fa, &p[i]);
        if (fa != -1)
            add_edge(fa, i);
        else
            root = i;
        pw[i] = p[i];
    }
    sort(pw + 1, pw + 1 + n);
    int tot = unique(pw + 1, pw + 1 + n) - pw - 1;
    for (int i = 1; i <= n; i++) p[i] = lower_bound(pw + 1, pw + 1 + tot, p[i]) - pw;
    dfs(root);
       for(int i=1;i<=n;i++){
    		printf("son=%d bro=%d c=%d s=%d\n",son[i],bro[i],c[i],s[i]);
    		// printf("p=%d ",p[i]);
    	}
    printf("%lld\n", dpf(root, k, tot));
    return 0;
}