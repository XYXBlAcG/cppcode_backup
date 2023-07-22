#include <cstdio>
#include <vector>
#include <algorithm>
using std::max;
const int N = 2e5 + 5;
struct Node{
    int v; long long w;
};
int n, m; long long distan, hot;
std::vector<Node> st[N];
int dep[N], fa[N][20]; long long amax[N][20], p[N], dis[N][20];
void dfs(int x, int father){
    dep[x] = dep[father] + 1;
    fa[x][0] = father;
    amax[x][0] = p[x];
    for (int i = 1; i < 20; i++){
        amax[x][i] = max(amax[x][i - 1], amax[fa[x][i - 1]][i - 1]);
        dis[x][i] = (dis[fa[x][i - 1]][i - 1] + dis[x][i - 1]);
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (auto v : st[x]){
        if(v.v != father) {
            dis[v.v][0] = v.w; 
            dfs(v.v, x);
        }
    }
}
void lca(int x, int y){
    distan = 0, hot = max(p[x], p[y]);
    if(dep[y] > dep[x]) std::swap(x, y);
    for (int i = 19; i >= 0; i--){
        if(dep[x] - dep[y] >= (1 << i)){
            distan += dis[x][i];
            hot = max(hot, amax[x][i]);
            x = fa[x][i];
        }
    }
    if(x == y) return;
    for (int i = 19; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            distan += dis[x][i] + dis[y][i];
            hot = max(amax[x][i], max(hot, amax[y][i]));
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    if(x != y){
        distan += dis[x][0] + dis[y][0];
        hot = max(hot, max(amax[x][0], max(amax[y][0], amax[fa[x][0]][0])));
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &p[i]);
    }
    for (int i = 1; i < n; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        st[u].push_back((Node){v, w});
        st[v].push_back((Node){u, w});
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++){
        int r, t;
        scanf("%d%d",&r,&t); lca(r, t);
        printf("%lld %lld\n", distan, hot);
    }
    return 0;
}