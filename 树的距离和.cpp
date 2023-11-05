#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e5 + 5;
int n, sz[N], ans;
struct Node{
    int v, w;
};
std::vector<Node> st[N];
void dfs(int u, int fath){
    for (auto v : st[u]){
        if(v.v == fath) continue;
        dfs(v.v, u);
        // printf("v.v = %lld, sz = %lld\n", v.v, sz[v.v]);
        ans += v.w * (n - sz[v.v]) * sz[v.v];
        sz[u] += sz[v.v];
    }
    sz[u]++;
}
signed main(){
    scanf("%lld", &n);
    for (int i = 1, u, v, w; i < n; i++){
        scanf("%lld%lld%lld", &u, &v, &w);
        st[u].push_back({v, w});
        st[v].push_back({u, w});
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}