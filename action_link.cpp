#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#define c1 [0][0]
#define c2 [0][1]
#define c3 [1][0]
#define c4 [1][1]
#define de(x) std::cout << #x << " = " << x << std::endl
typedef long long ll;
const int N = 1e5 + 4, M = 104, mod = 1e9 + 7;
int n, k, f[N][M][2][2], si[N], head[N], pedge;
ll tmp[M][2][2];
// std::vector<int> st[N];
struct Edge{
    int u, nxt, ver;
}edge[N];
void add(int u, int v){
    edge[++pedge] = {u, head[u], v};
    head[u] = pedge;
}
void cal(int &x, ll y){
    ll tmp = (ll)x;
    (tmp += y) %= mod;
    if(tmp < 0) tmp = (tmp + mod) % mod;
    x = (int)tmp;
}
void dfs(int u, int fa){
    si[u] = 1;
    f[u][1]c3 = f[u][0]c1 = 1;
    // for (int v : st[u]){
    for (int i = head[u]; i; i = edge[i].nxt){
        int v = edge[i].ver;
        if(v == fa) continue;
        dfs(v, u);
        for (int i = 0; i <= std::min(si[u], k); i++)
            for (int j = 0; j < 4; j++){
                int tx = "1010"[j] - '0', ty = "1100"[j] - '0';
                tmp[i][tx][ty] = (ll)f[u][i][tx][ty], f[u][i][tx][ty] = 0;
                // de(tmp[i][tx][ty]);
            }
        for (int i = 0; i <= std::min(si[u], k); i++){
            for (int j = 0; j <= std::min(si[v], k - i); j++){
                cal(f[u][i + j]c1, (ll)tmp[i]c1 * f[v][j]c2);
                // de((ll)f[u][i]c1 * tmp[j]c2 % mod);
                cal(f[u][i + j]c3, (ll)tmp[i]c3 * ((ll)f[v][j]c1 + f[v][j]c2));
                // de((ll)f[u][i]c3 * ((tmp[j]c1 + tmp[j]c2) % mod) % mod);
                cal(f[u][i + j]c2, (ll)tmp[i]c2 * ((ll)f[v][j]c2 + f[v][j]c4));
                // de((ll)f[u][i]c2 * ((tmp[j]c2 + tmp[j]c4) % mod) % mod);
                cal(f[u][i + j]c2, (ll)tmp[i]c1 * f[v][j]c4);
                // de((ll)f[u][i]c1 * tmp[j]c4 % mod);
                cal(f[u][i + j]c4, (ll)tmp[i]c3 * ((ll)f[v][j]c3 + f[v][j]c4));
                // de((ll)f[u][i]c3 * ((tmp[j]c3 + tmp[j]c4) % mod) % mod);
                cal(f[u][i + j]c4, (ll)tmp[i]c4 * ((ll)f[v][j]c1 + f[v][j]c2 + f[v][j]c3 + f[v][j]c4));
                // de((ll)f[u][i]c4 * ((tmp[j]c3 + tmp[j]c1) % mod) % mod);
                // de(tmp[j]c1), de(tmp[j]c2), de(tmp[j]c3), de(tmp[j]c4);
                // de(f[u][i + j]c1), de(f[u][i + j]c2), de(f[u][i + j]c3), de(f[u][i + j]c4);
            }
        }
        si[u] += si[v];
    }
}
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u)/*, st[u].push_back(v), st[v].push_back(u)*/;
    dfs(1, 0);
    printf("%d\n", (f[1][k]c2 + f[1][k]c4));
    return 0;
}