#include <cstdio>
#include <vector>
#include <algorithm>
using std::min;
#define int long long
#define INF 0x3f3f3f3f
const int N = 1e4 + 5;
std::vector<int> st[N];
int m, n, c[N], f[N][2];
void dfs(int u, int fa){
    for (auto v : st[u]){
        if(v == fa) continue;
        dfs(v, u);
        f[u][0] += min(f[v][0] - 1, f[v][1]);
        f[u][1] += min(f[v][0], f[v][1] - 1);
    }
}
signed main(){
    scanf("%lld%lld", &m, &n);
    for (int i = 1; i <= n; i++) scanf("%lld", c + i), f[i][c[i]] = 1, f[i][!c[i]] = INF;
    for (int i = n + 1; i <= m; i++) f[i][0] = f[i][1] = 1;
    for (int i = 1, u, v; i < m; i++){
        scanf("%lld%lld", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    dfs(1, -1);
    printf("%lld\n", min(f[1][0], f[1][1]));
    return 0;
}