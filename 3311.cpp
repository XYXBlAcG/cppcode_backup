#include <cstdio>
#include <vector>
#define int long long
const int N = 4e5 + 5;
int n, q1, q2, q3, q4, u, v, w, dep[N], fa[N][20], d[N], d2[N], sum[N], sum2[N];
std::vector<int> st[N];
void dfs(int x, int fath){
    dep[x] = dep[fath] + 1;
    fa[x][0] = fath;
    for (int i = 1; i < 20; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto v : st[x]){
        if(v != fath){
            dfs(v, x);
        }
    }
}
int lca(int x, int y){
    if(dep[y] > dep[x]) std::swap(x, y);
    for (int i = 19; i >= 0; i--){
        if(dep[x] - dep[y] >= (1 << i)) x = fa[x][i];
    }if(x == y) return x;
    for (int i = 19; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }return fa[x][0];
}
void dfs2(int x, int fath){
    for (auto v : st[x]){
        if(v != fath){
            d2[v] += d2[x];
            dfs2(v, x);
            d[x] += d[v];
        }
    }
}
void dfs3(int x, int fath){
    for (auto v : st[x]){
        if(v != fath){
            sum[v] += sum[x];
            dfs3(v, x);
            sum2[x] += sum2[v];
        }
    }
}
signed main(){
    scanf("%lld%lld%lld%lld%lld", &n ,&q1, &q2, &q3, &q4);
    for (int i = 1; i < n; i++){
        scanf("%lld%lld", &u, &v);
        st[u].push_back(v);
    }
    dfs(1, 0);
    for (int i = 1; i <= q1; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        d[u] += w; d[v] += w; d[lca(u, v)] -= w; d[fa[lca(u, v)][0]] -= w;
    }
    for (int i = 1; i <= q2; i++){
        scanf("%lld%lld", &u, &w);
        d2[u] += w;
    }
    dfs2(1, 0); 
    d[0] = 0, d2[0] = 0;
    for (int i = 0; i <= n; i++){
        sum2[i] = sum[i] = d[i] + d2[i];
    }
    // for (int i = 1; i <= n; i++){
    //     printf("%lld %lld\n", i, sum[i]);
    // }
    dfs3(1, 0);
    sum[0] = 0, sum2[0] = 0;
    for (int i = 1; i <= q3; i++){
        scanf("%lld%lld", &u, &v);
        printf("%lld\n", sum[u] + sum[v] - sum[lca(u, v)] - sum[fa[lca(u, v)][0]]);
    }
    for (int i = 1; i <= q4; i++){
        scanf("%lld", &u);
        printf("%lld\n", sum2[u]);
    }
    return 0;
}