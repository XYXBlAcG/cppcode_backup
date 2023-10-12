#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 2e5 + 5;
int n, d[N], sum[N], tot, res = INF;
std::vector<int> st[N];
void predfs(int u, int fa, int de){
    for (auto v : st[u]){
        if(v == fa) continue;
        predfs(v, u, de + 1);
        sum[u] += sum[v];
    }
    tot += d[u] * de;
}
void solve(int u, int fa, int ans){
    res = std::min(res, ans);
    for (auto v : st[u]){
        if(v == fa) continue;
        solve(v, u, ans + sum[1] - sum[v] * 2);
    }
}
signed main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", d + i), sum[i] = d[i];
    for (int i = 1; i < n; i++){
        int u = 0, v = 0;
        scanf("%lld%lld", &u, &v);
        st[u].push_back(v);
        st[v].push_back(u);
    }
    predfs(1, -1, 0);
    solve(1, -1, tot);
    printf("%lld\n", res);
    fclose(stdin);
    fclose(stdout);
    return 0;
}