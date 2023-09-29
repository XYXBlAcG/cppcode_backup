#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
const int N = 500000;
int n, s, a, b, t, ans, dis[N];
struct Edge{int v, w;};
std::vector<Edge> st[N];
void dfs(int u, int fa){
    for (auto v : st[u]) {
        if(v.v != fa) 
            dfs(v.v, u), dis[u] = std::max(dis[u], dis[v.v] + v.w);
    }
    for (auto& v : st[u]){
        if(v.v != fa){
            ans += dis[u] - dis[v.v] - v.w;
        }
    }
}
signed main(){
    scanf("%lld%lld", &n, &s);
    for (int i = 1; i < n; i++){
        scanf("%lld%lld%lld", &a, &b, &t);
        st[a].push_back({b, t});
        st[b].push_back({a, t});
    }
    dfs(s, -1);
    printf("%lld\n", ans);
    return 0;
}