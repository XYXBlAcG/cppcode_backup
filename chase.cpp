#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
#define INF 0x3f3f3f3f
using std::max;
const int N = 1e5 + 5, V = 105;
std::vector<int> st[N];
int n, num, f[N], recf[N][V][3], recg[N][V][3], vson[N], si[N];
void smax(int& x, int y){
    x = std::max(x, y);
}
void predfs(int u, int fa){
    si[u] = 1;
    for (auto v : st[u]){
        if(v == fa) continue;
        predfs(v, u);
        si[u] += si[v];
        vson[u] += f[v];
    }
}
int dfs(int u, int fa){
    int ans = 0;
    for (auto v : st[u]){
        if(v == fa) continue;
        smax(ans, dfs(v, u));
    }
    recf[u][0][1] = recg[u][0][1] = -INF;
    smax(recg[u][1][1], vson[u] + f[fa]);
    for (auto v : st[u]){
        // int top = std::min(num, si[u]);
        int top = num;
        for (int i = 0; i <= top; i++){
            smax(ans, max(recf[u][i][0], recf[u][i][1] + f[fa] - f[v]) + max(recg[v][top - i][0], recg[v][top - i][1]));
            smax(ans, max(recf[v][i][0], recf[v][i][1]) + max(recg[u][top - i][0], recg[u][top - i][1]));
        }
        for (int i = 1; i <= top; i++){
            smax(recf[u][i][0], max(recf[v][i][1], recf[v][i][0]));
            smax(recf[u][i][1], max(recf[v][i - 1][1], recf[v][i - 1][0]) + vson[u]);
            smax(recg[u][i][0], max(recg[v][i][1], recg[v][i][0]));
            smax(recg[u][i][1], max(recg[v][i - 1][1], recg[v][i - 1][0]) + vson[u] - f[v] + f[fa]);
        }
    }
    return ans;
}
signed main(){
    // freopen("chase.03.02.in", "r", stdin);
    // freopen("chase.out", "w", stdout);
    scanf("%lld%lld", &n, &num);
    for (int i = 1; i <= n; i++) scanf("%lld", f + i);
    for (int i = 1, u, v; i < n; i++){
        scanf("%lld%lld", &u, &v);
        st[u].push_back(v), st[v].push_back(u);
    }
    predfs(1, 0);
    printf("%lld\n", dfs(1, 0));
    return 0;
}