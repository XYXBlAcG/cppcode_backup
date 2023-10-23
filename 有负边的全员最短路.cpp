#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 2005;
int n, m, vis[N], cnt[N], dis[N], ans[N][N];
struct Node{
    int v, w;
};
std::vector<Node> st[N];
std::queue<int> que;
bool spfa(int s){
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) dis[i] = INF;
    memset(cnt, 0, sizeof(cnt));
    dis[s] = 0, vis[s] = 1;
    que.push(s);
    while(que.size()){
        auto u = que.front(); que.pop();
        vis[u] = 0;
        for (auto v : st[u]){
            if(dis[v.v] > dis[u] + v.w){
                dis[v.v] = dis[u] + v.w;
                cnt[v.v] = cnt[u] + 1;
                if(cnt[v.v] >= n) return 0; 
                if(!vis[v.v]) que.push(v.v), vis[v.v] = 1;
            }
        }
    }
    return 1;
}
signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        st[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++){
        spfa(i);
        for (int j = 1; j <= n; j++) ans[i][j] = dis[j];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf(ans[i][j] > (INF >> 1) ? "inf " : "%lld ", ans[i][j]);
        }putchar('\n');
    }
    return 0;
}