#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;
int t, n, m, sz[N], ans, p[N];
std::vector<int> st[N], dis;
void dfs(int u, int fath){
    for (auto v : st[u]){
        if(v == fath) continue;
        dfs(v, u), sz[u] += sz[v];
    }
    sz[u]++;
}
void dfs2(int u, int fath){
    for (auto v : st[u]){
        if(v == fath) continue;
        dis.push_back(sz[v] * (n - sz[v]));
        dfs2(v, u);
    }
}
void clean(){
    memset(p, 0, sizeof(p));
    memset(sz, 0, sizeof(sz));
    dis.clear();
    for (int i = 0; i <= N - 5; i++) st[i].clear();
    ans = 0;
}
bool cmp(int a, int b){return a > b;}
signed main(){
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        for (int i = 1, u, v; i < n; i++){
            scanf("%lld%lld", &u, &v);
            st[u].push_back(v), st[v].push_back(u);
        }
        scanf("%lld", &m);
        for (int i = 1; i <= m; i++)
            scanf("%lld", p + i);
        for (int i = m + 1; i < n; i++) p[i] = 1;
        dfs(1, 0), dfs2(1, 0);
        if(n-1>m){
            for(int i = m + 1 ; i < n ; i++)p[i]=1;
            m = n - 1;
        }
        std::sort(p + 1, p + 1 + m), n--;
        for (int i = n + 1; i <= m; i++) (p[n] *= p[i]) %= mod;
        std::sort(dis.begin(), dis.end());
        for (int i = 1; i <= n; i++)
            (ans += dis[i - 1] % mod * p[i] % mod) %= mod;
        printf("%lld\n", ans);
        clean();
    }
    return 0;
}