#include <cstdio>
#include <vector>
const int N = 5e5 + 5;
int n, m, a, b, c, d[N], fa[N][20], ans[N];
std::vector<int> st[N];
void dfs(int x, int father){
    d[x] = d[father] + 1;
    fa[x][0] = father;
    for (int i = 1; i < 20; i++)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto v : st[x])
        if(v != father) dfs(v, x);
}
int lca(int x, int y){
    if(d[y] > d[x]) std::swap(x, y);
    for (int i = 19; i >= 0; i--)
        if(d[x] - d[y] >= (1 << i)) x = fa[x][i];
    if(x == y) return x;
    for (int i = 19; i >= 0; i--)
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d",&a,&b,&c);
        int ab = lca(a, b), bc = lca(b, c), ac = lca(a, c), ans = 0, dt;
        if(ab == bc) ans = ac;
        else if(bc == ac) ans = ab;
        else ans = bc;
        dt = d[ab] + d[ac] + d[bc] - d[a] - d[b] - d[c];
        printf("%d %d\n", ans, -dt);
    }
    return 0;
}