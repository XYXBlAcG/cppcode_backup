#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 1e5 + 5;
int n, k, d[N], dep[N], fa[N][20], ans, sum[N];
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
void dfs2(int x, int fath){
    for (auto v : st[x]){
        if(v != fath){
            dfs2(v, x);
            d[x] += d[v];
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
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i < n; i++){
        int x, y;
        scanf("%d%d",&x,&y);
        st[x].push_back(y);
        st[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= k; i++){
        int sta, t;
        scanf("%d%d",&sta,&t); 
        d[sta]++; d[t]++; d[lca(sta, t)]--; d[fa[lca(sta, t)][0]]--;
    }
    dfs2(1, 0);
    for (int i = 1; i <= n; i++){
        ans = std::max(ans, d[i]);
    }
    printf("%d\n", ans);
    return 0;
}