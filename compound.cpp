#include <cstdio>
#include <vector>
const int N = 1e5 + 5, H = 525;
std::vector<int> st[N];
int n, dep[N], md[N], f[N][H], ans[H];
void dfs(int u){
    f[u][dep[u]]++; md[u] = dep[u];
    for (int v : st[u]){
        dep[v] = dep[u] + 1, dfs(v);
        for (int i = dep[u]; i <= md[u]; i++)
            for (int j = dep[v]; j <= md[v]; j++)
                ans[(i - dep[u]) ^ (j - dep[u])] += f[u][i] * f[v][j];
        for (int i = dep[v]; i <= md[v]; i++)
            f[u][i] += f[v][i];
        md[u] = std::max(md[v], md[u]);
    }
}
int main(){
    scanf("%d", &n);
    for (int i = 2, p; i <= n; i++) scanf("%d", &p), st[p].push_back(i);
    dfs(1);
    for (int i = 0; ans[i]; i++) printf("%d\n", ans[i]);
    return 0;
}