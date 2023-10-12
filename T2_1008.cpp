#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 1e5 + 5;
int n, m, in[N];
bool vis[N];
ll ans[N], t[N];
std::vector<int> st[N];
ll dfs(int u) { 
    if(u == n) return 0;
    if(vis[u]) return ans[u]; 
    vis[u] = 1;
    for (auto v : st[u]) {
        ans[u] = std::min(ans[u], dfs(v) + 1ll * t[v]);
        if(!vis[v]) dfs(v);
    }
    return ans[u];
}
int main() {
    freopen("circuit.in", "r", stdin);
    freopen("circuit.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", t + i);
        ans[i] = INF;
    }
    for (int i = 1; i <= m; i++) {
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
        in[v]++;
        // st[v].push_back(u);
    }
    // ans[n] = 0;
    // dfs(n);
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            printf("%d %lld\n", i, dfs(i));
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}