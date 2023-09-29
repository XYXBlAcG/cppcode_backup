#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f
const int N = 205, mod = 10007;
int T, n, g[3], si[N], w[N], f[N][N], F[N][N];
std::vector<int> st[N];
void clean(){
    for (int i = 1; i <= n; i++) st[i].clear();
    memset(si, 0, sizeof(si));
    memset(w, 0, sizeof(w));
    memset(f, 0, sizeof(f));
    memset(F, 0, sizeof(F));
    g[0] = g[1] = 0;
}
void find_g(int u, int fa){
    si[u] = 1, w[u] = 0;
    for (auto v : st[u]){
        if(v != fa){
            find_g(v, u);
            si[u] += si[v];
            w[u] = std::max(w[u], si[v]);
        }
    }
    w[u] = std::max(w[u], n - si[u]);
    if(w[u] <= (n >> 1)) g[g[0] > 0] = u;
}
void dfs_2(int u, int fa){
    si[u] = f[u][0] = f[u][1] = 1;
    for (auto v : st[u])
        if(v != fa){
            dfs_2(v, u), si[u] += si[v];
            for (int i = si[u]; i; i--)
                for (int j = 1; j <= std::min(i - 1, si[v]); j++)
                    (f[u][i] += f[u][i - j] * f[v][j] % mod) %= mod;
        }
}
int work(){
    int ans = 0;
    find_g(1, 0);
    if(g[1]){
        dfs_2(g[0], g[1]);
        dfs_2(g[1], g[0]);
        for (int i = 1; i <= std::min(si[g[1]], si[g[0]]); i++)
            (ans += f[g[0]][i] * f[g[1]][i] % mod) %= mod;
    }
    else{
        dfs_2(g[0], -1);
        int lp = -INF, sum = 0;
        for (auto v : st[g[0]]){
            lp = std::max(lp, si[v]), sum += si[v];
            for (int i = sum; i; i--){
                for (int j = std::min(si[v], i); j; j--){
                    if(j == i) (F[i][j] += f[v][i]) %= mod;
                    else for (int k = 1; k <= std::min(i, lp); k++)
                        (F[i][std::max(j, k)] += F[i - j][k] * f[v][j] % mod) %= mod;
                }
            }
        }
        ans = 1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; 2 * j <= i; j++){
                // printf("f[%lld][%lld] = %lld\n", i, j, f[i][j]);
                // printf("F[%lld][%lld] = %lld\n", i, j, F[i][j]);
                (ans += F[i][j]) %= mod;
            }
        }
    }
    return ans;
}
signed main(){
    scanf("%lld", &T);
    for (int tc = 1; tc <= T; tc++){
        scanf("%lld", &n);
        for (int i = 1, u, v; i < n; i++){
            scanf("%lld%lld", &u, &v);
            st[u].push_back(v);
            st[v].push_back(u);
        }
        printf("Case %lld: %lld\n", tc, work());
        clean();
    }
    return 0;
}