#include <bits/stdc++.h>
std::mt19937 rnd(251);
const int N = 25, inf = 1e7;
int n, m, tot, atot, mx;
struct Edge {
    int u, v;
} edge[N * N], e[N * N], aedge[N * N];
int f[N][N], d[N], h[N];
void floyd(int u, int v) {
    // for(int k=1;k<=n;k++){
    // 	// if(tp){
    // 	// 	for(int i=1;i<=n;i++)
    // 	// 		for(int j=1;j<=n;j++)
    // 	// 			if(i!=k&&j!=k&&i!=j){
    // 	// 				h[k]=std::min(h[k],d[i][k]+f[i][j]+d[k][j]);
    // 	// 				if(t) printf("i=%d,j=%d,k=%d[%d]\n",i,j,k,h[k]);
    // 	// 			}
    // 	// 	if(h[k]>=inf) return false;
    // 	// }
    // 	for(int i=1;i<=n;i++)
    // 		for(int j=1;j<=n;j++)
    // 			f[i][j]=std::min(f[i][j],f[i][k]+f[k][j]);
    // }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = std::min({ f[i][j], f[i][u] + f[v][j] + 1, f[i][v] + f[u][j] + 1 });
    // return true;
}
void solve() {
    std::shuffle(edge + 1, edge + tot + 1, rnd);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = inf;
    for (int i = 1; i <= n; i++) f[i][i] = 0, h[i] = inf;
    memset(d, 0, sizeof d);
    for (int i = 1; i <= tot; i++) {
        int u = edge[i].u, v = edge[i].v;
        if (f[u][v] + 1 < m)
            continue;
        e[++cnt] = { u, v }, f[u][v] = f[v][u] = 1, d[u]++, d[v]++, floyd(u, v);
    }
    // for(int i=1;i<=n;i++) if(d[i]<2) return;
    // if(!floyd(true)) return;
    if (cnt > mx)
        mx = atot = cnt, memcpy(aedge, e, sizeof e);
}
int main() {
    // freopen("build.in", "r", stdin), freopen("build.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) edge[++tot] = { i, j };
    for (int T = 1; T <= 15000; T++) solve();
    printf("%d\n", atot);
    for (int i = 1; i <= atot; i++) printf("%d %d\n", aedge[i].u, aedge[i].v);

    // for(int i=1;i<=n;i++)
    // 	for(int j=1;j<=n;j++)
    // 		f[i][j]=d[i][j]=inf;
    // for(int i=1;i<=n;i++) f[i][i]=d[i][i]=0,h[i]=inf;
    // for(int i=1;i<=tot;i++){
    // 	int u=edge[i].u,v=edge[i].v;
    // 	if(f[u][v]+1<m) continue;
    // 	f[u][v]=f[v][u]=1,floyd();
    // }
    // for(int i=1;i<=n;i++)
    // 	for(int j=1;j<=n;j++)
    // 		printf("f %d %d = %d\n",i,j,f[i][j]);
    // if(!floyd(true,true)) printf("!!!\n");
    // for(int i=1;i<=n;i++) printf("%d%c",h[i]," \n"[i==n]);
    return fclose(stdin), fclose(stdout), 0;
}