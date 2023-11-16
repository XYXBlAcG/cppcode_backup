#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;
int n, dis[N], val[N], pedge = 1, head[N], col[N], kk, fa[N][20], dep[N];
int id[5], icnt, deg[N], f[N][3], vf[N][3];
struct Edge {
    int nxt, ver;
} edge[N * 4];
void addedge(int u, int v) {
    edge[++pedge] = { head[u], v };
    head[u] = pedge;
}
namespace solve {
int ff(int u, int k) {
    if (!head[u])
        return k;
    if (vf[u][k])
        return f[u][k];
    vf[u][k] = 1;
    int ans = 1;
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].ver;
        //			printf("%lld -> %lld\n", u, v);
        int f1 = ff(v, 1), f0 = ff(v, 0);
        if (col[u] == 1) {
            if (col[v] == 1 && f1)
                ans *= f1;
            else
                ans *= (f1 + f0) % mod;
        } else {
            if (col[v] == 1 && f1) {
                ans *= f1;
            } else {
                if (k)
                    ans *= (f1 + f0) % mod;
                else if (f0)
                    ans *= f0;
            }
        }
        ans %= mod;
    }
    return f[u][k] = ans;
}
void main() { printf("%lld\n", ff(0, 1)); }
}  // namespace solve
namespace tc23 {
void dfs(int u, int fath) {
    dep[u] = dep[fath] + 1;
    fa[u][0] = fath;
    if(u == 0) fa[u][0] = -1;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = edge[i].nxt) {
        int v = edge[i].ver;
        dfs(v, u);
    }
}
int lca(int a, int b) {
    if (a == b)
        return a;
    if (dep[a] < dep[b])
        std::swap(a, b);
    for (int i = 19; ~i; i--) {
        if (dep[fa[a][i]] >= dep[b])
            a = fa[a][i];
    }
    if (a == b)
        return a;
    for (int i = 19; ~i; i--) {
        if (fa[a][i] != fa[b][i]) {
            a = fa[a][i], b = fa[b][i];
        }
    }
    return fa[a][0];
}
void main() {
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        if (col[i])
            id[++icnt] = i;
    }
    int lc = lca(id[1], id[2]);
    // printf("dep = %lld, %lld, %lld, %lld\n", dep[id[1]], dep[id[2]], dep[lc], dep[fa[lc][0]]);
    int dis = dep[id[1]] + dep[id[2]] - dep[lc] - dep[fa[lc][0]];
    printf("%lld\n", dis - 1);
}
}  // namespace tc23

signed main() {
    #ifdef ONLINE_JUDGE
    freopen("bwtree.in", "r", stdin);
    freopen("bwtree.out", "w", stdout);
    #endif

    scanf("%lld", &n);
    for (int i = 1, p; i < n; i++) {
        scanf("%lld", &p);
        addedge(p, i);
        deg[p]++, deg[i]++;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", col + i);
        if (col[i] == 1)
            kk++;
    }
    if (kk == 2) {
        tc23::main();
    } else if (kk == n - 1) {
        int id = 0;
        for (int i = 0; i < n; i++) {
            if (col[i] != 1)
                id = i;
        }
        printf("%lld\n", deg[id]);
    } else {
        solve::main();
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

//	int gg(int u, int k);
//	int ff(int u, int k){
//		if(!head[u]) return !!k;
//		if(vf[u][k]) return f[u][k]; vf[u][k] = 1;
//		int ans = 0;
//		for (int i = head[u]; i; i = edge[i].nxt){
//			int v = edge[i].ver;
//			if(col[v]){
//				ans += gg(v, 1);
//			}else{
//				if(k == 1) ans += (gg(v, 0) + gg(v, 1)) % mod;
//				else ans += gg(v, 0);
//			}
//			ans %= mod;
//		}
//		return f[u][k] = ans;
//	}
//	int gg(int u, int k){
//		if(vg[u][k]) return g[u][k]; vg[u][k] = 1;
//		int ans = 0;
//		for (int i = u; i; i = bro[i]){
//
//		}
//		return g[u][k] = ans;
//	}