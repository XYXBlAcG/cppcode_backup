#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
const int N = 1e4 + 5;
int n, m;
std::vector<int> st[N];
bool vis[N], anc[N];
int ans;
void dfs(int u){
    if(ans) return;
    vis[u] = 1;
    anc[u] = 1;
    for (int i = 0; i < st[u].size(); i++){
        int v = st[u][i];
        if(!vis[v]){
            dfs(v); 
        }else if(!anc[v]){
            ans = 1; return;
        }
    }
    anc[u] = 0;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int u = 0, v = 0;
        scanf("%d%d", &u, &v);
        st[u].push_back(v);
    }
    for (int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        ans = 0;
        dfs(i);
        printf("%d", ans);
    }
    return 0;
}