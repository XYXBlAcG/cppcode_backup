#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 5e5 + 5;
int n, m, s, dep[N], fa[N][22];
std::vector<int> st[N];
void dfs(int u, int fath){
    dep[u] = dep[fath] + 1, fa[u][0] = fath;
    for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : st[u]){
        if(v != fath) dfs(v, u);
    }
}
int lca(int a, int b){
    if(a == b) return a;
    if(dep[a] < dep[b]) std::swap(a, b);
    for (int i = 19; ~i; i--)
        if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    if(a == b) return a;
    for (int i = 19; ~i; i--){
        if(fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
    }
    return fa[a][0];
}
int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1, x = 0, y = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        st[x].push_back(y);
        st[y].push_back(x);
    }
    dfs(s, 0);
    for (int i = 1; i <= m; i++){
        int a = 0, b = 0;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}