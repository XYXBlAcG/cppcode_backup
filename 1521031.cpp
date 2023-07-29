#include <cstdio>
#include <vector>
const int N = 3e5 + 5;
int n, m, id[N], fa[N][20], dep[N];
std::vector<int> st[N];
void dfs(int x, int father){
    dep[x] = dep[father] + 1;
    fa[x][0] = father;
    for (int i = 1; i < 20; i++){
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (auto v : st[x]){
        if(v != father) dfs(v, x);
    }
}
int lca(int x, int y){
    if(dep[y] > dep[x]) std::swap(x, y);
    for (int i = 19; i >= 0; i--){
        if(dep[x] - dep[y] >= (1 << i)) x = fa[x][i];
    }
    if(x == y) return x;
    for (int i = 19; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            x = fa[x][i];
            y = fa[y][i];
        }
    }return fa[x][0];
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        int x, y;
        scanf("%d%d",&x,&y);
        st[x].push_back(y);
        st[y].push_back(x);
    }
    for (int i = 1; i < n; i++){
        scanf("%d", &id[i]);
    }

    return 0;
}