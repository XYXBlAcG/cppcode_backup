#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long
const int N = 5e5 + 5;
int n, m, root, fa[21][N], dep[N], vis[N];
std::vector<int> st[N];
void dfs(int x, int fath){
    dep[x] = dep[fath] + 1;
    fa[0][x] = fath;
    for (int i = 1; i <= 19; i++){
        fa[i][x] = fa[i - 1][fa[i - 1][x]];
    }
    for (auto v : st[x]){
        if(vis[v]) continue;
        if(v != fath) dfs(v, x);
    }
}
inline int lca(int x, int y){
    if(dep[x] < dep[y]) std::swap(x, y);
    for (int i = 19; i >= 0; i--)
        if(dep[x] - dep[y] >= (1 << i)) x = fa[i][x];
    if(x == y) return x;
    for (int i = 19; i >= 0; i--){
        if(fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
    }
    return fa[0][x];
}
signed main(){
    scanf("%lld%lld%lld", &n, &m, &root);
    for (int i = 1; i < n; i++){
        int x, y;
        scanf("%lld%lld", &x, &y);
        st[x].push_back(y);
        st[y].push_back(x);
    }
    dfs(root, 0);
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%lld%lld", &x, &y);
        printf("%lld\n", lca(x, y));
    }
    return 0;
}