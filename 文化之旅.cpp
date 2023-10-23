#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
const int N = 105;
int n, k, m, s, t, c[N], a[N][N], f[N][N];
int main(){
    freopen("culture.in", "r", stdin), freopen("culture.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &k, &m, &s, &t), memset(f, INF, sizeof(f));
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    for (int i = 1; i <= k; i++) for (int j = 1; j <= k; j++) scanf("%d", &a[i][j]);
    for (int i = 1, u, v, d; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &d);
        if(!a[c[v]][c[u]] && c[u] ^ c[v]) f[u][v] = std::min(f[u][v], d);
        if(!a[c[u]][c[v]] && c[v] ^ c[u]) f[v][u] = std::min(f[v][u], d);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i ^ j) for (int k = 1; k <= n; k++)
                    if(i ^ k && j ^ k) f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
    printf(f[s][t] == INF || c[s] == c[t] ? "-1\n" : "%d\n", f[s][t]);
    return fclose(stdin), fclose(stdout), 0;
}