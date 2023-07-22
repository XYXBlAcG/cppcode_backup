#include <cstdio>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
using std::max;
const int N = 3e5 + 5;
int n, m, f[N][2], vis[N][2];
std::vector<int> st[N];
int cost_in[N], cost_out[N];
int dp(int u, int c) {
    if(vis[u][c]) return f[u][c];
    vis[u][c] = 1; 
    int ans = -INF * c;
    for(auto v : st[u]) {
        if(c){
            ans = max(ans, max(dp(v, 1), dp(v, 0) + cost_out[v]));
        }else{
            if(st[v].size()){
                ans = max(ans, max(dp(v, 1) - cost_in[v], dp(v, 0)));
            }else{
                ans = max(ans, dp(v, 0));
            }
        }
    }
    return f[u][c] = ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        scanf("%d",&cost_out[i]);
    }
    for (int i = 1; i <= n; i++){
        scanf("%d",&cost_in[i]);
    }
    for (int i = 1; i <= m; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        st[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, max(dp(i, 0), dp(i, 1) - cost_in[i]));
    }
    printf("%d\n", ans);
    return 0;
}