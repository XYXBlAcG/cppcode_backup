#include <cstdio>
#include <vector>
const int N = 2e5 + 5;
int n, m, p[N], vis[N], ans[N];
std::vector<int> st[N];
void dfs(int x, int fath, int cnt){
    for (auto v : st[x]){
        if(v == fath) continue;
        ans[v] = cnt + p[v];
        dfs(v, x, cnt + p[v]);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i < n; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    for (int i = 1; i <= m; i++){
        int a, b;
        scanf("%d%d",&a,&b);
        p[a] += b;
    }
    ans[0] = p[0];
    dfs(0, 0, p[0]);
    for (int i = 0; i < n; i++){
        printf("%d ", (!ans[i]) ? p[i] : ans[i]);
    }
    return 0;
}