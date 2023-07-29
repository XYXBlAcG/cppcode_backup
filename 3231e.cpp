#include <cstdio>
#include <vector>
const int N = 5e5 + 5;
int n, m, root;
int dep[N], fa[N][20], ans[N];
// struct Node{
//     int v, idx;
// };
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
    scanf("%d%d%d",&n,&m,&root);
    for (int i = 1; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        st[x].push_back(y);
        st[y].push_back(x);
    }
    dfs(root, 0);
    ans[0] = 0;
    for (int i = 1; i <= m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        // ans[i] = lca((x + ans[i - 1]) % n + 1, (y + ans[i - 1]) % n + 1);
        ans[i] = lca(x, y);
    }
    for (int i = 1; i <= m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}