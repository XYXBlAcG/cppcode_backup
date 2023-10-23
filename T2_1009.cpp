#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
// #include "xyx.h"
// using namespace xyx;
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
using std::min;
using std::max;
const int N = 405;
std::vector<int> st[N];
int ff[N][N][N], gg[N][N][N], n, k, d[N], id[N], root, v[N], son[N], bro[N], bsize[N], size[N];
bool vf[N][N][N], vg[N][N][N];
void dfs(int u){
    int las = 0;
    // int cnt = st[u].size();
    for (auto v : st[u]){
        dfs(v);
        if(!son[u]) son[u] = v;
        else bro[las] = v;
        las = v;
        size[u] += size[v];
    }
    // for (auto v : st[u]) bsize[v] = --cnt;
    las = 0;
    for (auto v : st[u]){
        if(!las)
            bsize[v] = size[u] - size[v] + 1;
        else
            bsize[v] = bsize[las] - size[v];
        las = v;

    }

    // if(!u) return;
    // dfs(son[u]), dfs(bro[u]);
    // size[u] = bsize[son[u]] + 1, bsize[u] = size[u] + bsize[bro[u]];
}
int g(int, int, int);
int f(int i, int j, int k){
    if(!k) return INF;
    if(vf[i][j][k]) return ff[i][j][k]; vf[i][j][k] = 1;
    int ans = min(f(i, j, k - 1), (k >= id[i]) ? g(son[i], j - 1, k) + d[k] - d[id[i]] : g(son[i], j, k));
    return ff[i][j][k] = ans;
}
int g(int i, int j, int k){
    if(j < 0) return INF;
    if(!i) return !j ? 0 : INF;
    if(vg[i][j][k]) return gg[i][j][k]; vg[i][j][k] = 1;
    int ans = INF;
    for (int o = max(0ll, j - bsize[i]); o <= min(size[i], j); o++)
        ans = min(g(bro[i], j - o, k) + f(i, o, k), ans);
    return gg[i][j][k] = ans;
}
signed main(){
    freopen("radar.in", "r", stdin);
    freopen("radar.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) size[i] = 1;
    for (int i = 1, u, vv; i <= n; i++){
        scanf("%lld%lld", &u, &vv);
        // if(u != -1 && st[u].size()) bro[st[u].back()] = i;
        // else son[u] = i;
        if(u == -1) root = i;
        else st[u].push_back(i);
        v[i] = d[i] = vv;
    }
    std::sort(d + 1, d + 1 + n);
    int dlen = std::unique(d + 1, d + 1 + n) - d - 1;
    for (int i = 1; i <= n; i++)
        id[i] = std::lower_bound(d + 1, d + 1 + dlen, v[i]) - d;
    // for (int i = 1; i <= n; i++) d[id[i]] = v[i];
    // for (int i = 1; i <= n; i++) printf("%lld\n", id[i]);
    dfs(root);
    // for (int i = 1; i <= n; i++){
    //     printf("%lld %lld %lld %lld %lld\n", i, son[i], bro[i], bsize[i], size[i]);
    // }
    printf("%lld\n", f(root, k, dlen));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
2 0 7 7
5 0 6 6
6 0 3 3
0 0 1 1
4 3 5 2
7 0 2 2
0 0 1 1
5
*/
/*
son=7 bro=0 c=0 s=7
p=3 son=4 bro=0 c=0 s=5
p=1 son=6 bro=0 c=0 s=2
p=4 son=5 bro=3 c=2 s=2
p=4 son=0 bro=0 c=0 s=1
p=2 son=0 bro=0 c=0 s=1
p=1 son=0 bro=2 c=5 s=1
p=1 9
*/
/*
son=10 bro=0 c=0 s=15
son=3 bro=0 c=0 s=10
son=4 bro=0 c=0 s=9
son=8 bro=0 c=0 s=8
son=6 bro=0 c=0 s=3
son=12 bro=0 c=0 s=2
son=11 bro=2 c=10 s=3
son=13 bro=5 c=3 s=4
son=0 bro=0 c=0 s=1
son=0 bro=7 c=13 s=1
son=15 bro=0 c=0 s=2
son=0 bro=0 c=0 s=1
son=14 bro=9 c=1 s=2
son=0 bro=0 c=0 s=1
son=0 bro=0 c=0 s=1
6
*/