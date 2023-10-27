#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define int long long
const int N = 1e6 + 5;
std::queue<int> que;
int n, to[N], w[N], deg[N], ans, g[N], f[N];
void mx(int& a, int b){a = std::max(a, b);}
int solve(int x){
    // printf("x = %lld\n", x);
    int ed = x, pre = w[x], a1 = g[x], a2 = -0x3f3f3f3f3f3f3f3f, f1 = f[x], f2 = f[x]/*, sum = 0*/; 
    // x = to[x];
    // while(x != ed) sum += w[x], x = to[x];
    // printf("x = %lld, ed = %lld, sum = %lld\n", x, ed, sum);
    x = to[x];
    while(x != ed){
        deg[x] = 0;
        mx(a1, std::max(f[x] + pre + f1, g[x])), mx(a2, f[x] + f2 - pre);
        mx(f1, f[x] - pre), mx(f2, f[x] + pre), pre += w[x], x = to[x];
    }
    return std::max(a1, a2 + pre);
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", to + i, w + i), deg[to[i]]++;
    for (int i = 1; i <= n; i++) if(!deg[i]) que.push(i);
    while(que.size()){
        int u = que.front(); que.pop();
        mx(g[to[u]], std::max(f[to[u]] + f[u] + w[u], g[u])), mx(f[to[u]], f[u] + w[u]);
        if(!(--deg[to[u]])) que.push(to[u]);
    }
    for (int i = 1; i <= n; i++) if(deg[i]) ans += solve(i);
    printf("%lld\n", ans);
    return 0;
}